//
//  main.c
//  Mini_projet_Phone_Contacts_v1.0
//
//  Created by Mehdi on 6/19/19.
//  Copyright © 2019 Mehdi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
                            // pop_fist and last they have some bugs

                      /*                         THE FONT BACK CODING ARE DONE WITHOUT BUGS
                                                    JUST YOU HAVE TO WORK WITJ DESIGN
                                                                                                      */


/////////////////////////////////////////////     MENU & GRAPH     /////////////////////////////////////////////////////
void Menu_background(){
     int i,j;
    //Head
   printf("\n\n");
   for(i=0;i<31;i++){
    gotoxy(10+i,wherey());
    printf("%c",220);
   }
   gotoxy(wherex(),wherey());
   printf("%c MENU %c",221,222);

   for(i=0;i<31;i++){
    gotoxy(49+i,wherey());
    printf("%c",220);
   }

   //Body
   for(j=0;j<12;j++){
   gotoxy(10,wherey()+1);
   printf("%c",221);
  for(i=0;i<68;i++){
    gotoxy(11+i,wherey());
    printf("%c",176);
  }
  printf("%c",222);
   }

  //Footer
  printf("\n");
   for(i=0;i<70;i++){
    gotoxy(10+i,wherey());
    printf("%c",223);
   }
    gotoxy(11,wherey()-10);

}




void printtt(short int *m){
    int i;
    printf("\n\t\t\t\t%c",186);
   for(i=0;i<50;i++){
    if(m[i]){
        cprintf("%c",178);
    }else{
        printf("%c",176);
    }
  }
  printf("%c",186);
}


void logo(){
  int i;
  short int line1[50]={0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1};
  short int line2[50]={0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0};
  short int line3[50]={0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,1,1};
  short int line4[50]={0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1};
  short int line5[50]={0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,1,1};
  printf("\t\t\t\t%c",201);
  textcolor(BROWN);
     for(i=0;i<50;i++){
        printf("%c",205);
     }
     printf("%c",187);
  printtt(line1);
  printtt(line2);
  printtt(line3);
  printtt(line4);
  printtt(line5);

   printf("\n\t\t\t\t%c",200);
     for(i=0;i<50;i++){
        printf("%c",205);
     }
     printf("%c",188);
textcolor(WHITE);
printf("\n\n\n");
}


void logo_(){
     gotoxy(26,2);
     textcolor(BROWN);
    cprintf("////////////////////////////////////////////////////////////////////\n");
    gotoxy(25,3);
    cprintf("//");
    gotoxy(93,3);
    cprintf("//\n");
    gotoxy(25,4);
    cprintf("//");
    gotoxy(55,4);
    cprintf("CONTACTS");
    gotoxy(93,4);
    cprintf("//\n");
    gotoxy(25,5);
    cprintf("//");
    gotoxy(93,5);
    cprintf("//\n");
    gotoxy(26,6);
    cprintf("////////////////////////////////////////////////////////////////////\n");
    textcolor(WHITE);
    printf("\n\n\n");
}



void menu_chooe(char *text,int po){
  if(po){
      gotoxy(35,wherey()-1);
      textbackground(MAGENTA);
      cputs(text);
      textbackground(NULL);
  }else{
      gotoxy(11,wherey());
      textcolor(YELLOW);
      cputs(text);
      textcolor(WHITE);
  }
  printf("\n");

}

void menu(){
    logo();
    Sleep(200);
    Menu_background();
    gotoxy(wherex(),wherey()-1);
    menu_chooe("<>>>>>Press <1> Ajout Contact.",0);
    menu_chooe("<>>>>>Press <2> Modifie Contact.",0);
    menu_chooe("<>>>>>Press <3> Affiche All Contacts Data.",0);
    menu_chooe("<>>>>>Press <4> Supprime Contact.",0);
    menu_chooe("<>>>>>Press <5> Affiche Contacts avec un lettre donne.",0);
    menu_chooe("<>>>>>Press <6> Affiche Contacts Avec le meme Nom de family donne.",0);
    menu_chooe("<>>>>>Press <7> Affiche les donnes d'un contact dans Contacts.",0);
    menu_chooe("<>>>>>Press <8> Affiche Contacts avec meme Relation.",0);
    menu_chooe("<>>>>>Press <9> Affiche Contacts.",0);
    menu_chooe("<>>>>>Press <0> Pour Quite.",0);
    textcolor(YELLOW);
    gotoxy(wherex()+9,wherey()+1);
    cprintf("\n  --->Tapez votre option: ");
    textcolor(WHITE);
}

void menu_edit_contact(){
    Menu_background();
    menu_chooe("<>>>> Press <1> Modifie le Nom.",0);
    menu_chooe("<>>>> Press <2> Modifie le Prenom.",0);
    menu_chooe("<>>>> Press <3> Modifie le Numero Telephone.",0);
    menu_chooe("<>>>> Press <4> Modifie Email.",0);
    menu_chooe("<>>>> Press <5> Modifie la Relation.",0);
    menu_chooe("<>>>> Press <0> Pour Quite.",0);
    textcolor(YELLOW);
    gotoxy(wherex()+9,wherey()+4);
    cprintf("\n  --->Tapez votre option: ");
    textcolor(WHITE);

}



///////////////////////////////////////////////     PROGRAM     ///////////////////////////////////////////////////////

typedef struct Contact{//DONE CORRECT
    struct Contact *Prec;
    char first_name[20];
    char family_name[20];
    char Email[110];//30
    char Phone[15];
    char Rel[15];
    struct Contact *Rel_Next;
    struct Contact *Next;
}Contact;
typedef Contact *Contact_ptr;

typedef struct relation{
    char Name_rel[20];
    int taille_contact_same_rel;
    Contact_ptr first_rel_contact;
    Contact_ptr last_rel_contact;
    struct relation *relsuiv;
}relation;

typedef struct list_Contact{//DONE CORRECT
    struct list_Contact *Prec;
    char lettre;
    int taille;
    Contact_ptr first_list;
    Contact_ptr last_list;
    struct list_Contact *Next;

}list_Contact;


typedef struct Contacts{//DONE CORRECT
    list_Contact *first;
    list_Contact *last;
    int taille;
    int Rel_taille;
    relation *Rel_first;
    relation *Rel_last;
}Contacts;


void affiche_Contact_info(Contact e);
int pop_first_contacts(Contacts *book);

void reset_contacts(Contacts *Contacts_){//DONE CORRECT
    Contacts_->first=NULL;
    Contacts_->last=NULL;
    Contacts_->Rel_first=NULL;
    Contacts_->Rel_last=NULL;
    Contacts_->Rel_taille=0;
    Contacts_->taille=0;
}


void reset_list_Contact(list_Contact *Contact_){//DONE CORRECT
    Contact_->first_list=NULL;
    Contact_->last_list=NULL;
    Contact_->taille=0;
    Contact_->lettre='0';
    Contact_->Prec=NULL;
    Contact_->Next=NULL;

}




void create_Rel(Contacts *book,Contact_ptr e){//DONE CORRECT
    if (*e->Rel!='\0') {
        relation *p=(relation*)malloc(sizeof(relation));
        if (p!=NULL) {
            strcpy(p->Name_rel,e->Rel);
            e->Rel_Next=NULL;
            p->relsuiv=NULL;
            p->first_rel_contact=e;
            p->last_rel_contact=e;
            p->taille_contact_same_rel=1;
            book->Rel_taille=1;
            book->Rel_first=p;
            book->Rel_last=p;

        }
    }
}


relation *search_relation_position(Contacts book,char *rel_name){//DONE CORRECT
    relation *p;
    for (p=book.Rel_first; p!=NULL && strcmp(p->Name_rel, rel_name)!=0; p=p->relsuiv);
    return p;
}

void push_Rel_contact(Contacts *book,Contact_ptr e){//DONE CORRECT
    if(e->Rel[0]!='\0'){
    if (!book->Rel_taille) {
        create_Rel(book, e);
    } else {
        relation *ptr=search_relation_position(*book, e->Rel);
        if (ptr!=NULL) {
            e->Rel_Next=NULL;
            ptr->last_rel_contact->Rel_Next=e;
            ptr->last_rel_contact=e;
            ptr->taille_contact_same_rel++;
        } else {
            ptr=(relation*)malloc(sizeof(relation));
            strcpy(ptr->Name_rel, e->Rel);
            e->Rel_Next=NULL;
            ptr->first_rel_contact=e;
            ptr->last_rel_contact=e;
            ptr->relsuiv=NULL;
            ptr->taille_contact_same_rel=1;
            book->Rel_last->relsuiv=ptr;
            book->Rel_last=ptr;
            book->Rel_taille++;

        }

    }
    }
}

void pop_Rel(Contacts *book,Contact_ptr e){//DONE CORRECT
    if (*e->Rel!='\0') {
        relation *p=search_relation_position(*book, e->Rel);
        if (p!=NULL) {
            if(p->first_rel_contact==e && p->last_rel_contact==e){
                book->Rel_first=p->relsuiv;
                free(p);
                book->Rel_taille--;
            }else if (p->first_rel_contact==e) {
                p->first_rel_contact=e->Rel_Next;
                p->taille_contact_same_rel--;
            }else{
                Contact_ptr ptr1;
                for (ptr1=p->first_rel_contact;/*ptr1!=NULL && */ptr1->Rel_Next!=e; ptr1=ptr1->Rel_Next);
                if (ptr1->Rel_Next==p->last_rel_contact && e->Rel_Next==NULL) {
                    ptr1->Rel_Next=NULL;
                    p->last_rel_contact=ptr1;
                    p->taille_contact_same_rel--;
                } else {
                    ptr1->Rel_Next=ptr1->Rel_Next->Rel_Next;
                    p->taille_contact_same_rel--;
                }
            }
        }
    }
}



int pop_first_list(Contacts *book,list_Contact *list){//DONE check it later
    // some problems :Solved
    if (list==NULL || !list->taille) {
        return 0;
    } else {
        if (list->first_list==list->last_list) {
            pop_Rel(book,list->first_list);
            free(list->first_list);
            list->taille--;
            return -1;
        } else {
            Contact_ptr p;
            p=list->first_list;
            list->first_list=p->Next;
            list->first_list->Prec=NULL;
            pop_Rel(book, p);
            free(p);
            list->taille--;
        }

        return 1;
    }
}


int pop_last_list(Contacts *book,list_Contact *list){//DONE CORRECT

    if (list==NULL || !list->taille) {
        return 0;
    } else {
        if (list->taille==1) {
            pop_Rel(book, list->first_list);
            free(list->first_list);
            list--;
            return -1;
        }else{
            Contact_ptr p;
            p=list->last_list;
            list->last_list=p->Prec;
            list->last_list->Next=NULL;
            pop_Rel(book, p);
            free(p);
            list->taille--;
            return 1;
        }
    }
}


void free_list(Contacts *book,list_Contact *list_){ // DONE bugss!!
    while (list_!=NULL && pop_first_list(book,list_)!=0);
    free(list_);
    book->taille--;
}

int pop_first_contacts(Contacts *book){//DONE check it later by the chance for mistake is less than 10%
    // some problems too here
    list_Contact *p;
    if (book==NULL || !book->taille) {
        return 0;
    } else {
        if (book->taille==1) {
            free_list(book,book->first);
            reset_contacts(book);
            return 0;
        } else {
            p=book->first;
            book->first=p->Next;
            book->first->Prec=NULL;
            free_list(book,p);
            book->taille--;
            return 1;
        }

    }
}

int pop_last_contacts(Contacts *book){

    list_Contact *p;
    if (book==NULL || !book->taille) {
        return 0;
    } else {
        if (book->first==book->last) {
            free_list(book, book->last);
            reset_contacts(book);
            return 0;
        } else {
            p=book->last;
            book->last->Prec->Next=NULL;
            book->last=book->last->Prec;
            free_list(book, p);
            book->taille--;
            return 1;
        }
    }
}





void free_contacts(Contacts *book){ //DONE problems
    while (book!=NULL && pop_first_contacts(book)!=0);
    reset_contacts(book);
}

void create_contact_donne(Contact_ptr e,char *first_name,char *family_name,char *Phone,char *Email,char *relat){//DONE CORRECT //done
    strcpy(e->Email, Email);
    strcpy(e->Phone, Phone);
    strcpy(e->family_name, family_name);
    strcpy(e->first_name, first_name);
    e->Next=NULL;
    e->Prec=NULL;
    if (!strcmp(relat, "0")) {
        e->Rel[0]='\0';
    } else {
        strcpy(e->Rel, relat);
    }
    e->Rel_Next=NULL;
}


void create_list_Contact(Contacts *book,list_Contact *list,Contact_ptr e){//DONE CORRECT
    list->lettre=*e->family_name;
    list->first_list=e;
    list->last_list=e;
    list->Next=NULL;
    list->Prec=NULL;
    list->taille=1;
    push_Rel_contact(book, e);
}


void create_Contacts(Contacts *Contacts_,char *first_name,char *family_name,char *Phone,char *Email,char *relat){//DONE CORRECT
    list_Contact *list=(list_Contact*)malloc(sizeof(list_Contact));
    Contact_ptr e=(Contact_ptr)malloc(sizeof(Contact));
    if (list!=NULL && e!=NULL) {
        reset_list_Contact(list);
        create_contact_donne(e, first_name, family_name, Phone, Email,relat);
        create_list_Contact(Contacts_, list, e);
        Contacts_->first=list;
        Contacts_->last=list;
        Contacts_->taille=1;
    }else{
        printf("Memoir\n");
    }
}

void push_last_list_v2(Contacts *book,list_Contact *list,Contact_ptr e){ //DONE CORRECT
    if (!list->taille) {
        create_list_Contact(book,list, e);
    } else {
        e->Next=NULL;
        e->Prec=list->last_list;
        list->last_list->Next=e;
        if (list->taille==1) {
            list->last_list->Prec=NULL;
            list->first_list=list->last_list;
        }
        list->last_list=e;
        list->taille++;
        push_Rel_contact(book, e);
    }
}



void push_first_list_v2(Contacts *book,list_Contact *list,Contact_ptr e){ //DONE CORRECT
    if (!list->taille) {
        create_list_Contact(book,list, e);
    }else {
        e->Next=list->first_list;
        e->Prec=NULL;
        list->first_list->Prec=e;

        if (list->taille==1) {
            list->first_list->Next=NULL;
            list->last_list=list->first_list;
        }
        list->first_list=e;
        list->taille++;
        push_Rel_contact(book, e);

    }
}


void push_first_Contacts_v2(Contacts *book_,list_Contact *list_){ //DONE CORRECT
    list_->Next=book_->first;
    list_->Prec=NULL;
    book_->first->Prec=list_;
    book_->first=list_;
    book_->taille++;
}


void push_last_Contacts_v2(Contacts *book_,list_Contact *list_){ //DONE CORRECT
    list_->Next=NULL;
    list_->Prec=book_->last;
    book_->last->Next=list_;
    book_->last=list_;
    book_->taille++;
}



void push_name_order_by_family(Contacts*book,list_Contact *list_,Contact_ptr p,Contact_ptr e){ // problems with NULL at the end
    // DONE CORRECT
    // THIS FUCNTION IS ABOUT ORDERING THE CONTACTS BY FAMILY NAME AND FIRST NAME

    for (; p!=NULL && !strcmp(p->family_name, e->family_name) && (strcmp(p->first_name, e->first_name)<=0); p=p->Next);

    if (p==NULL || strcmp(p->family_name, e->family_name)==-1) {//
        push_last_list_v2(book,list_, e);
    } else if (p==list_->first_list){
        push_first_list_v2(book,list_, e);
    }else{
        if (!strcmp(p->family_name, e->family_name) && p==list_->last_list && strcmp(p->first_name, e->first_name)<0) {
            push_last_list_v2(book, list_, e);
        } else {
            e->Prec=p->Prec;
            e->Next=p;
            p->Prec->Next=e;
            p->Prec=e;
            push_Rel_contact(book, e);
        }
    }
}



void push_list_position(Contacts *book,list_Contact *list_,Contact_ptr e){ // recheck it some problems at the end with NULL : soloved
    // Another bug Soloved

    if ((strcmp(list_->first_list->family_name, e->family_name)>0)||(!strcmp(list_->first_list->family_name, e->family_name) && strcmp(list_->first_list->first_name, e->first_name)==1)) {
        // problem here in If conduction Soloved!!
        push_first_list_v2(book,list_, e);
    } else if((strcmp(list_->last_list->family_name, e->family_name)<0) || (!strcmp(list_->last_list->family_name, e->family_name)&& strcmp(list_->last_list->first_name, e->first_name)==-1)){
        // Another bug Soloved !!
        push_last_list_v2(book,list_,e);
    }else{

        Contact_ptr p;
        for (p=list_->first_list; p!=NULL && (strcmp(p->family_name, e->family_name)==-1); p=p->Next);

        if (p!=NULL && !strcmp(p->family_name, e->family_name)) {
            push_name_order_by_family(book,list_,p,e);
        } else{
            if (strcmp(p->family_name, e->family_name)==1) {
                e->Prec=p->Prec;
                e->Next=p;
                p->Prec=e;
                p->Prec->Next=e;
                push_Rel_contact(book, e);
            }
        }
        list_->taille++;

    }
}



void push_Contacts_position(Contacts *book,list_Contact *list){
    // CORRECT
    if (book->first->lettre>list->lettre || list->lettre=='0') {
        push_first_Contacts_v2(book, list);
    } else if(book->last->lettre<list->lettre){
        push_last_Contacts_v2(book,list);
    }else{
        list_Contact *p;
        for (p=book->first->Next; p->Next!=NULL && p->lettre<list->lettre ; p=p->Next);
        // a b c e          d
        list->Next=p;
        list->Prec=p->Prec;
        p->Prec->Next=list;
        p->Prec=list;
        book->taille++;
    }
}


////////////////////////////////////////////// la recherche ////////////////////////////////////////////////

list_Contact *search_by_lettre(Contacts book,char lettre){//DONE CORRECT
    list_Contact *p;
    for (p=book.first;p!=NULL && p->lettre<lettre ; p=p->Next);
    if (p!=NULL && lettre==p->lettre) {
        return p;
    } else{
        return NULL;
    }
}


Contact_ptr search_by_family_name(Contacts book,char *family_name){//DONE CORRECT
    Contact_ptr e=NULL;
    list_Contact *p=search_by_lettre(book, family_name[0]);
    if(p!=NULL){
        for (e=p->first_list; e!=NULL && strcmp(e->family_name, family_name)<0; e=e->Next);
    }
    if (e!=NULL && !strcmp(e->family_name, family_name)) {
        return e;
    } else {
        //printf("%s Not found",family_name);
        return NULL;
    }
}

Contact_ptr search_contact(Contacts book,char *family_name,char *first_name){ // DONE CORRECT
    Contact_ptr p=search_by_family_name(book, family_name);
    if (p!=NULL) {
        for (;p!=NULL && !strcmp(family_name, p->family_name) && strcmp(p->first_name, first_name)!=0; p=p->Next);
        if (p!=NULL && !strcmp(family_name, p->family_name) && !strcmp(p->first_name, first_name)) {
            return p;
        } else {
            goto not_found;
        }
    } else {
    not_found: return NULL;
    }
}


Contact_ptr search_contact_by_id(Contacts book,int id){
    Contact_ptr p;
    list_Contact *list;
    int i=1;
    for(list=book.first; list!=NULL; list=list->Next){
        for(p=list->first_list; p!=NULL; p=p->Next,i++){
            if(i==id){
                return p;
            }
        }
    }
    return NULL;
}


//////////////////////////////////////////////     AJOUTE    //////////////////////////////////////////////

void Add_New_Contact(Contacts *book,char *first_name,char *family_name,char *Phone,char *Email,char *relat){
    // DONE CORRECT !!

    if (!book->taille) {
        create_Contacts(book, first_name, family_name, Phone, Email, relat);
    } else {
        list_Contact *list;
        Contact_ptr e=(Contact_ptr)malloc(sizeof(Contact));
        if(e==NULL){
            printf("Memoire");
        }else{
            create_contact_donne(e, first_name, family_name, Phone, Email, relat);
            list=search_by_lettre(*book, family_name[0]);
             /*if (!strcmp(first_name, "mehdi")) {
             //DEBUG
             }*/
            if (list==NULL) {
                list=(list_Contact*)malloc(sizeof(list_Contact));
                if (list!=NULL) {
                    reset_list_Contact(list);
                    create_list_Contact(book, list, e);
                    push_Contacts_position(book, list);
                }else{
                    printf("Memoir\n");
                }

            } else {

                push_list_position(book, list, e);
            }
        }

    }
}


///////////////////////////////////////////     FILES     ////////////////////////////////////////////////


void get_data_from_file(Contacts *book,char *file_name){//DONE CHECK IT LATER  //problem with relation
    Contact data;
    FILE *F=fopen(file_name, "rt");
    if (F!=NULL) {
        fgets(data.Email, sizeof(data.Email), F);
        while (fscanf(F,"%s\t%s\t%s\t%s\t%s",data.first_name,data.family_name,data.Phone,data.Email,data.Rel)!=EOF) {
            Add_New_Contact(book, data.first_name, data.family_name, data.Phone, data.Email, data.Rel);
        }
    }else{
        //clearcreaan()
        //call the function void Contacts_vide();
    }
    fclose(F);
}


void back_up_file_data(Contacts book){//DONE CHECK IT LATER  // CORRECT
    FILE *f;
    list_Contact *p;
    Contact_ptr e;
    f=fopen("back_up.txt", "wt");
    fprintf(f, "first_name family_name   mobile   email Relation\n");
    p=book.first;
    while (p!=NULL){
        for (e=p->first_list; e!=NULL; e=e->Next) {
            if (e->Rel[0]=='\0') {
                fprintf(f, "%s\t%s\t%s\t%s\t%s\n",e->first_name,e->family_name,e->Phone,e->Email,"0");
            } else {
                fprintf(f, "%s\t%s\t%s\t%s\t%s\n",e->first_name,e->family_name,e->Phone,e->Email,e->Rel);
            }
        }
        p=p->Next;
    }
    fclose(f);
}


void contact_file_data(Contacts book){//DONE CHECK IT LATER // CORRECT
    FILE *f;
    list_Contact *p;
    int i,j;
    Contact_ptr data;
    back_up_file_data(book);
    f=fopen("Contacts.txt", "wt");
    p=book.first;

    fprintf(f,"\t\t\t            ////////////////////////////////////////////////////\n");
    fprintf(f,"\t\t\t          //                                                   //\n");
    fprintf(f,"\t\t\t         //                      CONTACTS                     //\n");
    fprintf(f,"\t\t\t        //                                                   //\n");
    fprintf(f,"\t\t\t         //////////////////////////////////////////////////// \n");
    fprintf(f,"\n\n\n");

    //fprintf(f, "first_name family_name   mobile   email \t\trelation\n");

   fprintf(f,"\tFIRST_NAME           FAMILY_NAME          MOBILE          EMAIL                          RELATION        \n");

    while (p!=NULL) {
        fprintf(f, "\t-------------------------------------------------- %c -------------------------------------------------\n",p->lettre);
        for (data=p->first_list; data!=NULL; data=data->Next) {
            //fprintf(f, "%s\t%s\t%s\t%s\t%s\n",data->first_name,data->family_name,data->Phone,data->Email,data->Rel);

            fprintf(f,"\t%s",data->first_name);
            j=strlen(data->first_name);
            for(i=0;i<=sizeof(data->first_name)-j;i++){
                fprintf(f," ");
            }

            fprintf(f,"%s",data->family_name);
            j=strlen(data->family_name);
            for(i=0;i<=sizeof(data->family_name)-j;i++){
                fprintf(f," ");
            }

            fprintf(f,"%s",data->Phone);
            j=strlen(data->Phone);
            for(i=0;i<=sizeof(data->Phone)-j;i++){
                fprintf(f," ");
            }

            fprintf(f,"%s",data->Email);
            j=strlen(data->Email);
            for(i=0;i<=30-j;i++){
                fprintf(f," ");
            }

            fprintf(f,"%s",data->Rel);
            j=strlen(data->Rel);
            for(i=0;i<=sizeof(data->Rel)-j;i++){
                fprintf(f," ");
            }
            fprintf(f,"\n");

        }
        p=p->Next;
    }

    fclose(f);
}



//////////////////////////////////////////// MODIFICATION  /////////////////////////////////////////////////

int delete_contact(Contacts *book,char *first_name,char *last_name){// CORRECT DONE

    Contact_ptr e=search_contact(*book, last_name, first_name);

    if (e!=NULL) {
        list_Contact *list=search_by_lettre(*book, last_name[0]);

        if (e->Prec==NULL || e->Next==NULL) {

            if (list!=NULL) {

                if (e->Prec==NULL) {
                    if (pop_first_list(book,list)==-1) {
                        if (book->first==list) {
                            pop_first_contacts(book);
                        } else if(book->last==list){
                            pop_last_contacts(book);
                        }else{
                            list->Prec->Next=list->Next;
                            list->Next->Prec=list->Prec;
                            free(list);
                            book->taille--;
                        }
                        book->taille--;
                    }

                }else if (e->Next==NULL){
                    pop_last_list(book,list);
                }
            }else{goto fin;}
        } else {
            e->Next->Prec=e->Prec;
            e->Prec->Next=e->Next;
            pop_Rel(book, e);
            free(e);
            list->taille--;
        }
        return 1;
    } else {
    fin: printf("\t******* %s %s Can not be deleted\tNOT FOUND *******\n",first_name,last_name);
        return 0;
    }
}

void edite_contact_data(Contacts *book){// DONE CORRECT // //problem with memoir flash
    char new_nom[50],new_prenom[200];
    int option;
    Contact data;
    Contact_ptr e;
    printf("\t-->tapez le Nom: ");
    gets(new_nom);
    printf("\t-->Tapez le Prenom de cette Contact: ");
    gets(new_prenom);
    e=search_contact(*book, new_nom, new_prenom);
    if (e!=NULL) {
        clrscr();
        do {
            logo();
            menu_chooe("************* MODIFIE CONTACT *************\n\n",1);
            affiche_Contact_info(*e);
            printf("\n");
            menu_edit_contact();
            scanf("%d",&option);
            fflush(stdout);
            fflush(stdin);
            clrscr();
            logo();
            menu_chooe("************* MODIFIE CONTACT *************\n\n",1);
            switch (option) {
                case 1://CORRECT
                    menu_chooe("************* MODIFIE LE NOM *************\n",1);
                    data=*e;
                    delete_contact(book,data.first_name,data.family_name);
                    printf("\t-->Tapez le nom: ");
                    gets(new_nom);
                    Add_New_Contact(book, data.first_name,new_nom, data.Phone, data.Email, data.Rel);
                    option=0;
                    break;
                case 2://CORRECT
                    menu_chooe("************* MODIFIE LE PRENOM *************\n",1);
                    data=*e;
                    delete_contact(book,data.first_name,e->family_name);
                    printf("\t-->Tapez le prenom: ");
                    gets(new_prenom);
                    Add_New_Contact(book, new_prenom, data.family_name, data.Phone, data.Email ,data.Rel);
                    option=0;
                    break;
                case 3://CORRECT
                    menu_chooe("************* MODIFIE LE NUMERO*************\n",1);
                    printf("\t-->Tapez le Numero: ");
                    gets(new_nom);
                    strcpy(e->Phone, new_nom);
                    break;
                case 4://correct
                    menu_chooe("************* MODIFIE L'EMAIL *************\n",1);
                    printf("\t-->Tapez Email: ");
                    gets(new_prenom);
                    strcpy(e->Email, new_prenom);
                    break;
                case 5: //CORRECT
                    menu_chooe("************* MODIFIE LA RELATION *************\n",1);
                    printf("\t-->Tapez la Relation");
                    gets(new_nom);
                    pop_Rel(book, e);
                    strcpy(e->Rel,new_nom);
                    push_Rel_contact(book, e);
                    break;
                default:
                    goto end;
                    break;
            }
                    textcolor(GREEN);
                    gotoxy(30,wherey());
                    cprintf("********** CONTACT EDITED SUCCESSFUL **********");
                    textcolor(WHITE);
                    Sleep(1);
                    printf("\n");

        end:clrscr();
        } while (option);

    } else {
        printf("\t %s %s Not found.\n",new_nom,new_prenom);
    }
}



////////////////////////////////////////////   AFFICHAGE   ////////////////////////////////////////////////

void affiche_Contact_info(Contact e){//DONE CORRECT
    gotoxy(25,wherey());
    textcolor(YELLOW);
    cprintf("first_name: %s\n",e.first_name);

    gotoxy(25,wherey());
    cprintf("family_name: %s\n",e.family_name);

    gotoxy(25,wherey());
    cprintf("Phone number: %s\n",e.Phone);

    gotoxy(25,wherey());
    cprintf("Email: %s\n",e.Email);

    gotoxy(25,wherey());
    cprintf("Relation: %s\n",e.Rel);
    textcolor(WHITE);
}

void affiche_list(list_Contact list){//DONE CORRECT
    Contact_ptr p;
    for (p=list.first_list; p!=NULL; p=p->Next) {
        affiche_Contact_info(*p);
        textcolor(BLUE);
        gotoxy(18,wherey());
        cprintf("--------------------------------------------\n");
        textcolor(WHITE);
    }
}

void affiche_Contacts(Contacts book){//DONE CORRECT
    if(book.taille){
    list_Contact *ptr;
    for (ptr=book.first; ptr!=NULL; ptr=ptr->Next) {
        gotoxy(18,wherey());
        textcolor(YELLOW);
        cprintf("--------------------- %c --------------------\n",ptr->lettre);
        textcolor(WHITE);
        affiche_list(*ptr);
    }
    }else{
        printf("\t******** List Contacts est Vide!! *******\n");
    }
}



void affiche_by_family_name(Contacts book,char *family_name){//DONE CORRECT
    Contact_ptr e=search_by_family_name(book, family_name);
    if (e!=NULL) {
        gotoxy(18,wherey());
        textcolor(YELLOW);
        cprintf("---------------------- %s ----------------------\n",family_name);
        for (; e!=NULL && !strcmp(e->family_name, family_name); e=e->Next) {
            affiche_Contact_info(*e);
            gotoxy(18,wherey());
            textcolor(BLUE);
            cprintf("--------------------------------------------\n");
            textcolor(WHITE);
        }
    }else{
        printf("\t******* Y pas %s dans la lise de contacts!! *******",family_name);
    }
}

void affiche_by_lettre(Contacts book,char lettre){//DONE CORRECT
    list_Contact *p;
    p=search_by_lettre(book, lettre);
    gotoxy(18,wherey());
    textcolor(YELLOW);
    cprintf("-------------------------- %c -------------------------\n",lettre);
    textcolor(WHITE);
    printf("\n");
    if (p==NULL) {
        printf("\t******* There's no Contact start with '%c' on Contacts list!! *******\n\n",lettre);
    } else {
        affiche_list(*p);
    }
}

void affiche_by_Relation_donne(Contacts book, char*relat_name){ //CORRECT DONE
    relation *p=search_relation_position(book,relat_name);
    if(book.first!=NULL ){
    if (p==NULL) {
        printf("\t******* Ya pas de %s Relation dans votre Contacts!! *******\n",relat_name);
    } else {
        Contact_ptr ptr;
        gotoxy(18,wherey());
        textcolor(YELLOW);
        cprintf("---------------------- %s ----------------------\n\n",relat_name);
        ptr=p->first_rel_contact;

        for(;ptr!=NULL;ptr=ptr->Rel_Next){
            affiche_Contact_info(*ptr);
            gotoxy(18,wherey());
            textcolor(BLUE);
            cprintf("--------------------------------------------\n");
            textcolor(WHITE);
        }

    }
    }else{
       printf("\t******** List Contacts est Vide!! *******\n");
    }
}


void affiche_list_by_id(list_Contact list,int *id){
       Contact_ptr p;
       for(p=list.first_list;p!=NULL;p=p->Next,(*id)++){
        gotoxy(18,wherey());
        textcolor(YELLOW);
        cprintf("%d   %s %s\n",*id,p->first_name,p->family_name);
        if(p->Next!=NULL){
        gotoxy(18,wherey());
        cprintf("----------------------------------------------\n");
        }
        textcolor(WHITE);
       }
}


void affiche_Contacts_(Contacts book){
    //search_contact_by_id
    if(book.taille){
    list_Contact *ptr;
    int id=1;
    Contact_ptr p;
    gotoxy(18,wherey());
    cprintf("id\n");

    for (ptr=book.first; ptr!=NULL; ptr=ptr->Next) {
        gotoxy(18,wherey());
        textcolor(YELLOW);
        cprintf("---------------------- %c ---------------------\n",ptr->lettre);
        textcolor(WHITE);
        affiche_list_by_id(*ptr,&id);
    }
    gotoxy(18,wherey()+2);
    textcolor(YELLOW);
    cprintf("-->Tapez id de Contat: ");
    scanf("%d",&id);
    textcolor(WHITE);
    clrscr();
    p=search_contact_by_id(book,id);
       if(p!=NULL){
           logo();
           menu_chooe("************* AFFICHE CONTACTS *************\n\n",1);
          affiche_Contact_info(*p);
       }else{
          gotoxy(20,wherey()+2);
          cprintf("id est over donne.");
       }
    }else{
        printf("\t******** List Contacts est Vide!! *******\n");
    }
}




void main() {
    // insert code here...
    int option;
    char c;
    Contact_ptr p;
    Contact new_data;
    Contacts *book;
    book =(Contacts*)malloc(sizeof(Contacts));
    if(book!=NULL){
    reset_contacts(book);
    }else{
        printf("error");
    }
    get_data_from_file(book, "back_up.txt");
    do {
        menu();
        scanf("%d",&option);
        fflush(stdin);
        clrscr();
        logo();
    switch (option) {
            case 1:
                do{
                clrscr();
                logo();
                menu_chooe("************* INSERTION *************\n\n",1);
                Sleep(0.3);
                printf("\t-->Tapez le Nom: ");
                gets(new_data.family_name);
                printf("\t-->Tapez le Prenom: ");
                gets(new_data.first_name);
                printf("\t-->Tapez le Numero Telephone: ");
                gets(new_data.Phone);
                printf("\t-->Tapez l'Email: ");
                gets(new_data.Email);
                printf("\t-->Tapez La relaton si pas de relation tapez '0': ");
                gets(new_data.Rel);

                if (!strcmp(new_data.Rel, "0")) {
                    new_data.Rel[0]='\0';
                }

                Add_New_Contact(book, new_data.first_name, new_data.family_name, new_data.Phone, new_data.Email, new_data.Rel);
                    printf("\n\t-->Tapez ENTRE pour ajoute autre contact ou ('0' pour Quiti): ");
                    c=getchar();
                }while (c!='0');
                clrscr();
                goto end_1;
                break;
            case 2:
                menu_chooe("************* MODIFIE CONTACT *************\n\n",1);
                menu_chooe("************* Tapez le Nom et Prenom de Contact  *************\n",1);
                edite_contact_data(book);
                goto end_1;
                break;
            case 3:
                menu_chooe("************* AFFICHE ALL CONTACTS DATA *************\n\n",1);
                Sleep(0.2);
                affiche_Contacts(*book);
                break;
            case 4:
                menu_chooe("************* SUPPRIMER *************\n\n",1);
                Sleep(0.3);
                printf("\t-->tapez le Nom: ");
                gets(new_data.family_name);
                printf("\t-->Tapez le Prenom de cette Contact: ");
                gets(new_data.first_name);
                if (delete_contact(book, new_data.first_name, new_data.family_name)) {
                    textcolor(GREEN);
                    gotoxy(30,wherey()+3);
                    cprintf("********** CONTACT DELETED SUCCESSFUL **********");
                    textcolor(WHITE);
                    printf("\n");
                }
                break;
            case 5:
                menu_chooe("************* AFFICHE CONTACTS BY SAME CHAR FAMILY NAME *************\n\n",1);
                Sleep(0.3);
                printf("\t-->Tapez la lettre: ");
                c=getchar();
                clrscr();
                logo();
                menu_chooe("************* AFFICHE CONTACTS BY SAME CHAR FAMILY NAME *************\n\n",1);
                affiche_by_lettre(*book, c);
                break;
            case 6:
                menu_chooe("************* AFFICHE CONTACTS BY FAMILY NAME *************\n\n",1);
                Sleep(0.3);
                printf("\t-->Tapez le Nom: ");
                gets(new_data.family_name);
                clrscr();
                logo();
                menu_chooe("************* AFFICHE CONTACTS BY FAMILY NAME *************\n\n",1);
                affiche_by_family_name(*book, new_data.family_name);
                break;
            case 7:
                printf("\t-->Tapez le Nom: ");
                gets(new_data.family_name);
                printf("\t-->Tapew le Prenom: ");
                gets(new_data.first_name);
                clrscr();
                logo();
                p=search_contact(*book, new_data.family_name, new_data.first_name);
                if(p!=NULL){
                    affiche_Contact_info(*p);
                }else{
                   gotoxy(30,wherey()+3);
                   textcolor(RED);
                   cprintf("******* %s %s NOT FOUND IN YOUR CONTACTS LIST *******",new_data.family_name,new_data.first_name);
                   textcolor(WHITE);
                   printf("\n");
                }
                break;
            case 8:
                menu_chooe("************* AFFICHE CONTACTS WITH SAME RELATION *************\n\n",1);
                Sleep(0.3);
                fflush(stdin);
                printf("\t-->Tapez la Relation: ");
                scanf("%s",new_data.Rel);
                clrscr();
                logo();
                menu_chooe("************* AFFICHE CONTACTS WITH SAME RELATION *************\n\n",1);
                affiche_by_Relation_donne(*book, new_data.Rel);
                break;
            case 9:
                menu_chooe("************* AFFICHE CONTACTS *************\n\n",1);
                Sleep(0.2);
                affiche_Contacts_(*book);
                break;
            default:
                goto end_1;
                break;
        }
        printf("\n");
        printf("\n\n\t-->Press Entre pour continue.........");
        getch();
        end_1:clrscr();
    } while (option!=0);
    gotoxy(30,5);
    textcolor(RED);
    cprintf("************* PLEASE WAIT TO SAVE YOUR DATA *************\n\n");
    textcolor(WHITE);
    contact_file_data(*book);

    gotoxy(20,wherey()+1);
    textcolor(GREEN);
    cprintf("************* YOOUR CONTACTS ARE SAVED SUCESSFUL !! IN 'Contacts.txt' *************\n\n");
    textcolor(WHITE);

    Sleep(5000);
}
