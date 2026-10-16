    #include <iostream>
    #include <cstdlib>

    struct Node {
        std::string data;
        Node* next;
        Node* prev;
        Node(std::string value) { data = value; next = nullptr; prev = nullptr;}
    };

    class doubly_Linked_List {
    public:
        Node* head;

        doubly_Linked_List() {
            head = nullptr;
        }
        
        void insertAtEnd(std::string value) {
            Node* newNode = new Node(value);
            
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node* curr = head;
            while (curr->next != nullptr) {
            curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;       
        }

        void display() {
            Node* curr = head;
            while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
            }
            std::cout << "\n";
        }

        void swap(){

            if (head==nullptr || head->next==nullptr)
            {
                return;
            }
            
            
            Node* last=head;
            while (last->next!=nullptr){

            last=last->next;
            }
            std:: string temp=head->data;
            head->data=last->data;
            last->data=temp;
            
        }

        void move(){
            int choice;
            std::cout<<"\nEnter choice :\n1-Forward\n2-Backward\n";
            std::cin>>choice;
            Node* curr=head;
            Node* last=head;
        
            //forward
            if (choice==1) {
                if (head == nullptr) {
                    std::cout << "List is empty!\n";
                    return;
                }
                while (curr!=nullptr){
                std::cout<<curr->data<<"   ";
                curr=curr->next;
            }
            
            }
            else if (choice==2){
            if (last == nullptr) {
                std::cout << "List is empty!\n";
                return;
            }
            while (last->next!=nullptr){
            last=last->next;
            }
            while (last!=nullptr){
                std::cout<<last->data<<"   ";
                last=last->prev;
            }
            
        }
            else{
                std::cout<<"Wrong Choice! must e 1 or 2";
            }

        }
        void rearrangeSeats() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        int count = 0;
        Node* curr = head;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        Node* left = head->next;
        Node* right = head;

        while (right->next != nullptr) {
            right = right->next;
        }

        right = right->prev;

        int leftPos = 2;
        int rightPos = count - 1;

        while (leftPos < rightPos) {
            std::string temp = left->data;
            left->data = right->data;
            right->data = temp;

            leftPos += 2;
            rightPos -= 2;

            if (leftPos >= rightPos) {
                break;
            }

            left = left->next->next;
            right = right->prev->prev;
        }
    }
        
    };


    struct Item {
        std::string name;
        Item* next;
    };

    struct Section {
        std::string name;
        Item* items;
        Section* next;
    };

    struct Store {
        std::string name;
        std::string city;
        Section* sections;
        Store* next;
    };

    class InventoryManagement {
    public:
        Store* head;

        InventoryManagement() {
            head = nullptr;
        }

    void addStore(std::string name, std::string city) {
        Store* newStore = new Store;

        newStore->name = name;
        newStore->city = city;
        newStore->sections = nullptr;
        newStore->next = nullptr;

        if (head == nullptr) {
            head = newStore;
        }
        else {
            Store* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newStore;
        }
    }

    void addSection(std::string storeName, std::string sectionName) {
        Store* s = head;

        while (s != nullptr && s->name != storeName) {
            s = s->next;
        }
        if (s == nullptr) {
            std::cout << "Store not found!\n";
            return;
        }
        Section* sec = new Section;
        sec->name = sectionName;
        sec->items = nullptr;
        sec->next = nullptr;

        if (s->sections == nullptr) {
            s->sections = sec;
        }
        else {
            Section* curr = s->sections;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = sec;
        }
    }

    void addItem(std::string storeName, std::string sectionName,
                std::string itemName) {
        Store* s = head;

        while (s != nullptr && s->name != storeName) {
            s = s->next;
        }
        if (s == nullptr) {
            std::cout << "Store not found!\n";
            return;
        }
        Section* sec = s->sections;
        while (sec != nullptr && sec->name != sectionName) {
            sec = sec->next;
        }

        if (sec == nullptr) {
            std::cout << "Section not found!\n";
            return;
        }
        Item* item = new Item;
        item->name = itemName;
        item->next = nullptr;
        if (sec->items == nullptr) {
            sec->items = item;
        }
        else {
            Item* curr = sec->items;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = item;
        }
    }

    void removeItem(std::string storeName, std::string sectionName,std::string itemName) {
        Store* s = head;
        while (s != nullptr && s->name != storeName) {
            s = s->next;
        }
        if (s == nullptr) {
            std::cout << "Store not found!\n";
            return;
        }
        Section* sec = s->sections;
        while (sec != nullptr && sec->name != sectionName) {
            sec = sec->next;
        }
        if (sec == nullptr) {
            std::cout << "Section not found!\n";
            return;
        }
        Item* curr = sec->items;
        Item* prev = nullptr;

        while (curr != nullptr && curr->name != itemName) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            std::cout << "Item not found!\n";
            return;
        }
        if (prev == nullptr) {
            sec->items = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
        std::cout << "Item removed successfully!\n";
    }

    void displaySectionItems(std::string storeName, std::string sectionName) {
        Store* s = head;
        while (s != nullptr && s->name != storeName) {
            s = s->next;
        }
        if (s == nullptr) {
            std::cout << "Store not found!\n";
            return;
        }
        Section* sec = s->sections;

        while (sec != nullptr && sec->name != sectionName) {
            sec = sec->next;
        }
        if (sec == nullptr) {
            std::cout << "Section not found!\n";
            return;
        }
        Item* curr = sec->items;
        std::cout << sectionName << ": ";

        while (curr != nullptr) {
            std::cout << curr->name << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    void displayStoreItems(std::string storeName) {
        Store* s = head;
        while (s != nullptr && s->name != storeName) {
            s = s->next;
        }
        if (s == nullptr) {
            std::cout << "Store not found!\n";
            return;
        }
        Section* sec = s->sections;
        std::cout << "Store: " << s->name << "\n";
        while (sec != nullptr) {
            std::cout << sec->name << ": ";
            Item* curr = sec->items;
            while (curr != nullptr) {
                std::cout << curr->name << " ";
                curr = curr->next;
            }
            std::cout << "\n";
            sec = sec->next;
        }
    }

    };

    int main() {
        doubly_Linked_List list;
        doubly_Linked_List songList;
        InventoryManagement inventory;
        doubly_Linked_List seats;

        // Task 1: Desk Swapping
        list.insertAtEnd("Alice");
        list.insertAtEnd("Bob");
        list.insertAtEnd("Charlie");
        list.insertAtEnd("Dana");
        list.insertAtEnd("Eva");
        list.insertAtEnd("Frank");

        std::cout << "Original Desk List: ";
        list.display();
        std::cout<<"\n";
        list.swap();
        

        std::cout << "Desk List After Swapping: ";
        list.display();
        std::cout<<"\n";

        // Task 2: Music Playlist
        songList.insertAtEnd("Shape of You");
        songList.insertAtEnd("Perfect");
        songList.insertAtEnd("Believer");
        songList.insertAtEnd("Faded");

        std::cout << "\nMusic Playlist:\n";
        songList.move();
        std::cout<<"\n";

        // Task 3: Inventory Management
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

        std::cout << "\nInventory: Lahore Store\n";
        inventory.displayStoreItems("Lahore Store");
        std::cout<<"\n";

        std::cout << "\nItems in Toys Section:\n";
        inventory.displaySectionItems("Lahore Store", "Toys");
        std::cout<<"\n";

        inventory.removeItem("Lahore Store", "Toys", "Car");

        std::cout << "\nToys After Removing Car:\n";
        inventory.displaySectionItems("Lahore Store", "Toys");
        std::cout<<"\n";
        

        seats.insertAtEnd("1");
        seats.insertAtEnd("2");
        seats.insertAtEnd("3");
        seats.insertAtEnd("4");
        seats.insertAtEnd("5");
        seats.insertAtEnd("6");
        seats.insertAtEnd("7");
        seats.insertAtEnd("8");
        seats.insertAtEnd("9");

        std::cout << "Original Seat Arrangement:\n";
        seats.display();

        seats.rearrangeSeats();

        std::cout << "After Rearranging Seats:\n";
        seats.display();
        std::cout<<"\n";


        system("pause");
        return 0;
    }
