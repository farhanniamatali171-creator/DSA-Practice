
#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
    Node* prev;
    Node(std::string value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

 void insertAtEnd(std::string value) {
    Node* newNode = new Node(value);
     if (head == nullptr) {
        head = newNode;
        return;
      }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
     }
    current->next = newNode;
    newNode->prev = current;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

 void swapFirstAndLast() {
    if (head == nullptr || head->next == nullptr) {
        return;
     }
      Node* last = head;
       while (last->next != nullptr) {
          last = last->next;
        }
      std::string temp = head->data;
      head->data = last->data;
      last->data = temp;
    }

 void move() {
        int choice;
        std::cout << "1 - Forward\n";
        std::cout << "2 - Backward\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (head == nullptr) {
           std::cout << "List is empty.\n";
           return;
        }
        if (choice == 1) {
            Node* current = head;
            while (current != nullptr) {
              std::cout << current->data << " ";
              current = current->next;
            }
            std::cout << "\n";
        }
        else if (choice == 2) {
            Node* current = head;

          while (current->next != nullptr) {
             current = current->next;
            }
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->prev;
            }
            std::cout << "\n";
        }
        else {
            std::cout << "Wrong choice. Enter 1 or 2.\n";
        }
    }

  void rearrangeSeats() {
      if (head == nullptr || head->next == nullptr) {
          return;
        }
        int count = 0;
        Node* current = head;

       while (current != nullptr) {
          count++;
          current = current->next;
        }
        Node* left = head->next;
        Node* right = head;

        while (right->next != nullptr) {
            right = right->next;
        }
        right = right->prev;
        int leftPosition = 2;
        int rightPosition = count - 1;

        while (leftPosition < rightPosition) {
            std::string temp = left->data;
            left->data = right->data;
            right->data = temp;  

            leftPosition += 2;
            rightPosition -= 2;

            if (leftPosition >= rightPosition) {
                break;
            }
            left = left->next->next;
            right = right->prev->prev;
        }
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

struct Item {
    std::string name;
    Item* next;

    Item(std::string itemName) {
        name = itemName;
        next = nullptr;
    }
};

struct Section {
    std::string name;
    Item* items;
    Section* next;

    Section(std::string sectionName) {
        name = sectionName;
        items = nullptr;
        next = nullptr;
    }
};

struct Store {
    std::string name;
    std::string city;
    Section* sections;
    Store* next;

    Store(std::string storeName, std::string storeCity) {
        name = storeName;
        city = storeCity;
        sections = nullptr;
        next = nullptr;
    }
};

class InventoryManagement {
public:
    Store* head;
    InventoryManagement() {
        head = nullptr;
    }
    void addStore(std::string name, std::string city) {
        Store* newStore = new Store(name, city);
        if (head == nullptr) {
            head = newStore;
        }
        else {
            Store* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newStore;
        }
    }

    void addSection(std::string storeName, std::string sectionName) {
        Store* store = head;

        while (store != nullptr && store->name != storeName) {
            store = store->next;
        }

        if (store == nullptr) {
            std::cout << "Store not found.\n";
            return;
        }
        Section* newSection = new Section(sectionName);

        if (store->sections == nullptr) {
            store->sections = newSection;
        }
        else {
            Section* current = store->sections;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newSection;
        }
    }

    void addItem(std::string storeName, std::string sectionName,
                 std::string itemName) {
        Store* store = head;

        while (store != nullptr && store->name != storeName) {
            store = store->next;
        }
        if (store == nullptr) {
            std::cout << "Store not found.\n";
            return;
        }
        Section* section = store->sections;

        while (section != nullptr && section->name != sectionName) {
            section = section->next;
        }

        if (section == nullptr) {
            std::cout << "Section not found.\n";
            return;
        }
        Item* newItem = new Item(itemName);

        if (section->items == nullptr) {
            section->items = newItem;
        }
        else {
            Item* current = section->items;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newItem;
        }
    }

    void removeItem(std::string storeName, std::string sectionName, std::string itemName) {
        Store* store = head;
        while (store != nullptr && store->name != storeName) {
            store = store->next;
        }

        if (store == nullptr) {
            std::cout << "Store not found.\n";
            return;
        }
        Section* section = store->sections;

        while (section != nullptr && section->name != sectionName) {
            section = section->next;
        }
        if (section == nullptr) {
            std::cout << "Section not found.\n";
            return;
        }
        Item* current = section->items;
        Item* previous = nullptr;

        while (current != nullptr && current->name != itemName) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Item not found.\n";
            return;
        }
        if (previous == nullptr) {
            section->items = current->next;
        }
        else {
            previous->next = current->next;
        }
        delete current;
        std::cout << "Item removed successfully.\n";
    }

    void displaySectionItems(std::string storeName,std::string sectionName) {
        Store* store = head;

        while (store != nullptr && store->name != storeName) {
            store = store->next;
        }
        if (store == nullptr) {
            std::cout << "Store not found.\n";
            return;
        }
        Section* section = store->sections;

        while (section != nullptr && section->name != sectionName) {
            section = section->next;
        }
        if (section == nullptr) {
            std::cout << "Section not found.\n";
            return;
        }
        std::cout << section->name << ": ";
        Item* current = section->items;

        while (current != nullptr) {
            std::cout << current->name << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

 void displayStoreItems(std::string storeName) {
    Store* store = head;

    while (store != nullptr && store->name != storeName) {
        store = store->next;
    }
    if (store == nullptr) {
        std::cout << "Store not found.\n";
        return;
      }
    std::cout << "Store: " << store->name<< " (" << store->city << ")\n";
    Section* section = store->sections;

    while (section != nullptr) {
        std::cout << section->name << ": ";
        Item* current = section->items;
            while (current != nullptr) {
                std::cout << current->name << " ";
                current = current->next;
            }
        std::cout << "\n";
        section = section->next;
       }
    }

~InventoryManagement() {
    Store* store = head;
    while (store != nullptr) {
      Section* section = store->sections;
        while (section != nullptr) {
          Item* item = section->items;

            while (item != nullptr) {
               Item* nextItem = item->next;
               delete item;
               item = nextItem;
              }
            Section* nextSection = section->next;
            delete section;
            section = nextSection;
            }
        Store* nextStore = store->next;
        delete store;
        store = nextStore;
        }
    }
};

int main() {
    DoublyLinkedList deskList;
    DoublyLinkedList songList;
    DoublyLinkedList seats;
    InventoryManagement inventory;

    //Desk Swapping
    std::cout << "Task 1: Desk Swapping\n";
    deskList.insertAtEnd("Alice");
    deskList.insertAtEnd("Bob");
    deskList.insertAtEnd("Charlie");
    deskList.insertAtEnd("Dana");
    deskList.insertAtEnd("Eva");
    deskList.insertAtEnd("Frank");

    std::cout << "Original Desk List: ";
    deskList.display();

    deskList.swapFirstAndLast();

    std::cout << "Desk List After Swapping: ";
    deskList.display();

    //Music Playlist
    std::cout << "\nTask 2: Music Playlist\n";
    songList.insertAtEnd("Shape of You");
    songList.insertAtEnd("Perfect");
    songList.insertAtEnd("Believer");
    songList.insertAtEnd("Faded");
    songList.move();

    //Inventory Mnagement
    std::cout << "\nTask 3: Inventory Management\n";
    inventory.addStore("Lahore Store", "Lahore");
    inventory.addStore("Karachi Store", "Karachi");

    inventory.addSection("Lahore Store", "Toys");
    inventory.addSection("Lahore Store", "Grocery");
    inventory.addSection("Karachi Store", "Fruits");

    inventory.addItem("Lahore Store", "Toys", "Car");
    inventory.addItem("Lahore Store", "Toys", "Doll");
    inventory.addItem("Lahore Store", "Grocery", "Rice");
    inventory.addItem("Lahore Store", "Grocery", "Sugar");
    inventory.addItem("Karachi Store", "Fruits", "Apple");
    inventory.addItem("Karachi Store", "Fruits", "Mango");

    inventory.displayStoreItems("Lahore Store");

    std::cout << "\nItems in Toys Section:\n";
    inventory.displaySectionItems("Lahore Store", "Toys");

    inventory.removeItem("Lahore Store", "Toys", "Car");

    std::cout << "Toys After Removing Car:\n";
    inventory.displaySectionItems("Lahore Store", "Toys");

    //Seat Rearragement
    std::cout << "\nTask 4: Seat Rearrangement\n";
    seats.insertAtEnd("1");
    seats.insertAtEnd("2");
    seats.insertAtEnd("3");
    seats.insertAtEnd("4");
    seats.insertAtEnd("5");
    seats.insertAtEnd("6");
    seats.insertAtEnd("7");
    seats.insertAtEnd("8");
    seats.insertAtEnd("9");

    std::cout << "Original Seat Arrangement: ";
    seats.display();

    seats.rearrangeSeats();

    std::cout << "After Rearranging Seats: ";
    seats.display();

    
   return 0;
}
