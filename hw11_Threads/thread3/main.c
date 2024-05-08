#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_OF_STORES 5 // Кол-во магазинов
#define NUM_OF_BUYERS 3 // Кол-во покупателей 
#define LOADER_ADD_PRODUCTS 5000 // Кол-во продуктов, которое привозит погрузчик в магазин 
// Диапазон, в котором определяется максимальная и минимальная потребность покупателей
#define BUYER_NEED_MAX 100000 
#define BUYER_NEED_MIN 97000 
// Диапазон, в котором генерируется максимальная и минимальная вместимость в магазины
#define STORE_PRODUCT_MAX 10000 
#define STORE_PRODUCT_MIN 900 

int stores[NUM_OF_STORES];  // тут будет храниться кол-во товаров
pthread_mutex_t mutexes[NUM_OF_STORES];  // для каждого магазина свой мьютекс
int servised  = 0; // Кол-во покупателей, которым больше не нужны товары

struct Buyer_data{ // структура покупателя
	
    int id;
    int need;
};
struct Buyer_data  buyers_data[NUM_OF_BUYERS];

void *buyer_behavior(void *arg){ // тут покупатель будет искать товары и покупать
    
	struct Buyer_data *buyer_data = (struct Buyer_data*) arg;

    printf("Покупатель: %d | Требуется =  %d\n", buyer_data->id, buyer_data->need);

    while (buyer_data->need > 0){ // Тут покупатель покупает продукты, пока потребности не закончатся
        
		sleep(2);
        int curr_store = rand() % NUM_OF_STORES; 
        pthread_mutex_lock(&mutexes[curr_store]); // занимаем рандомный магазин
        printf("Покупатель %d | В магазине %d | Купил %4d Товаров | Требуется ещё = %4d\n", buyer_data->id,  curr_store + 1,  stores[curr_store],  buyer_data->need - stores[curr_store]);
        buyer_data->need -= stores[curr_store];
        stores[curr_store] = 0;
        pthread_mutex_unlock(&mutexes[curr_store]); // освобождаем наш магазин
    }
    printf("Покупатель %d | Требуется = 0\n", buyer_data->id);
    servised++;
    pthread_exit(0);
}

void *loader_behavior(void *param){// тут погрузчик добавляет товары

	while (servised < NUM_OF_BUYERS){
    
        int curr_store = rand() % NUM_OF_STORES;
		pthread_mutex_lock(&mutexes[curr_store]);// погрузчик занимает рандомный магазин
			stores[curr_store] += LOADER_ADD_PRODUCTS;
			printf("Погрузчик: добавил продукты %d | Колличество добавленных продуктов %d\n", curr_store + 1, stores[curr_store]);
        pthread_mutex_unlock(&mutexes[curr_store]);// освобождаем наш магазин
		sleep(2);
	}
	pthread_exit(0);
}

void stores_init(int *stores){ // определяем кол-во продуктов в магазине изначально

    for (int i = 0; i < NUM_OF_STORES; i++){
    
        stores[i] = rand() % (STORE_PRODUCT_MAX - STORE_PRODUCT_MIN + 1) + STORE_PRODUCT_MIN;
        printf("Магазин: %d | Товары: %d\n", i + 1, stores[i]);
    }
}

void mutexes_init(pthread_mutex_t *mutexes){ 

    for (int i = 0; i < NUM_OF_STORES; i++){
    
        if (pthread_mutex_init(&mutexes[i], NULL)){
        
             perror("ERROR: mutex create failed");
             exit(EXIT_FAILURE);
        }
    }
}

void buyers_init(pthread_t *buyers){ // Определяем нужды покупателей

    for (int i = 0; i < NUM_OF_BUYERS; i++){
    
        buyers_data[i].id = i + 1;
        buyers_data[i].need = rand() % (BUYER_NEED_MAX - BUYER_NEED_MIN + 1) + BUYER_NEED_MIN;
    }
    
    for (int i = 0; i < NUM_OF_BUYERS; i++){
    
        void *curr_buyer = &buyers_data[i];
        if (pthread_create(&buyers[i], NULL, buyer_behavior, curr_buyer) != 0){
        
             perror("ERROR: buyer create failed");
             exit(EXIT_FAILURE);
        }
    }
}

void loader_init(pthread_t loader){ 

	if (pthread_create(&loader, NULL, loader_behavior, NULL) != 0){
    
		perror("ERROR: loader create failed");
		exit(EXIT_FAILURE);
	}
}

void all_threads_join(pthread_t *buyers, pthread_t loader){ 

    for (int i = 0; i < NUM_OF_BUYERS; i++){ 
    
		pthread_join(buyers[i], NULL);
    }
	pthread_join(loader, NULL);
}

void all_mutex_destroy(){ // дестроим мьютексы

    for (int i = 0; i < NUM_OF_STORES; i++){ 
    
	    pthread_mutex_destroy(&mutexes[i]);
    }
}

int main(void){

    srand(time(NULL));
    pthread_t buyers[NUM_OF_BUYERS];// Создаем поток покупателей
   	pthread_t loader;//создаем поток погрузчика

    stores_init(stores);
    mutexes_init(mutexes);
    buyers_init(buyers);
    loader_init(loader);
	
    all_threads_join(buyers, loader);
	all_mutex_destroy();
	
    exit(EXIT_SUCCESS);
}
