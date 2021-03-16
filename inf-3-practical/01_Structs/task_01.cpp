#include <iostream>
#include <cstring>
using namespace std;

const unsigned MAX_NAME_SIZE     = 257;
const unsigned PHONE_SIZE        = 10;
const unsigned MAX_CONTACTS_SIZE = 1024;

struct Contact{
    char name[MAX_NAME_SIZE];
    unsigned phone[PHONE_SIZE];
    unsigned id;
};

struct ContactList{
    Contact contacts[MAX_CONTACTS_SIZE];
    unsigned contactsCount;
};

Contact createNewContact(char name[MAX_NAME_SIZE], unsigned phone[PHONE_SIZE], unsigned id) {

    Contact newContact;

    strcpy(newContact.name, name);

    for(int i = 0; i < PHONE_SIZE; i++) {
        newContact.phone[i] = phone[i];
    }

    newContact.id = id;

    return newContact;
}

bool addContact(ContactList& list, const Contact& contact) {

    if(list.contactsCount == MAX_CONTACTS_SIZE)
        return false;

    list.contacts[list.contactsCount] = contact;
    list.contactsCount++;
    
    return true;
}

bool deleteContact(ContactList& list, unsigned contactID) {

    int contactIndex = -1;

    for(int i = 0; i < list.contactsCount; i++) {

        if(list.contacts[i].id == contactID) {
            contactIndex = i;
        }
    }

    if(contactIndex == -1) 
        return false;

    swap(list.contacts[list.contactsCount], list.contacts[list.contactsCount - 1]);
    list.contactsCount--;
    return true;
}

void sortByID(ContactList& list) {

    for(int i = 0; i < list.contactsCount - 1; i++) {

        int minIndex = i;
        for(int j = i + 1; j < list.contactsCount; j++) {

            if((list.contacts[j]).id < (list.contacts[minIndex]).id)
                minIndex = j;
        }

        if(minIndex != i)
            swap(list.contacts[i], list.contacts[minIndex]);
    }
}

int findContactByID(const ContactList& list, unsigned contactID) {

    for(int i = 0; i < list.contactsCount; i++) {
        if((list.contacts[i]).id == contactID) {
            return i;
        }
    }
    return -1;
}

bool isSortedById(const ContactList& list) {

   for(int i = 0; i < list.contactsCount - 1; i++) {
       if((list.contacts[i]).id > (list.contacts[i+1]).id)
        return false;
   } 

   return true;
}

int binarySearch(const ContactList& list, unsigned contactID) {

    int l = 0;
    int r = list.contactsCount - 1;

    while(l <= r) {

        int mid = l + (r - l)/2;

        if((list.contacts[mid]).id == contactID)
            return mid;

        if(contactID > (list.contacts[mid]).id)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}


int main() {

    return 0;
}



