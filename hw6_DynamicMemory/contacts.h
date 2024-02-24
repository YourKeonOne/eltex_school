#ifndef CONTACTS_H
#define CONTACTS_H

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

void add_contact(int *c, struct abonent **cntct);
void delete_contact(int *c, struct abonent **cntct);
void search_contact(int *c, struct abonent **cntct);
void show_all_contacts(int *c, struct abonent **cntct);
void clear(struct abonent **cntct);

#endif 
