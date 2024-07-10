#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Items {
    string itemName;
    short quantity;
};

class ItemManager {
    public:
    void addItem(list<Items>& itemList) {
        Items newItem;
        cout << "Item name: "; 
        getline(cin, newItem.itemName);

        cout << "Quantity: "; 
        cin >> newItem.quantity;
        cin.ignore();

        itemList.push_back(newItem);
        cout << "Item added successfully.\n";
    }

    void removeItem(list<Items>& itemList) {
        string itemName;
        cout << "Enter item name to remove: "; 
        getline(cin, itemName);
        
        bool found = false;
        for (auto it = itemList.begin(); it != itemList.end(); ++it) {
            if (it->itemName == itemName) {
                itemList.erase(it);
                cout << "Item removed.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Item not found in the inventory.\n";
        }
    }

    void viewItems(const list<Items>& itemList) {
        if (itemList.empty()) {
            cout << "The inventory is empty.\n";
            return;
        }
        
        cout << "Items in the inventory:\n";
        for (const auto& i : itemList) {
            cout << "Item: " << i.itemName << "\nQuantity: " << i.quantity << "\n";
        }
    }

    void updateItem(list<Items>& itemList) {
        string itemName;
        cout << "Enter item name to update: ";
        getline(cin, itemName);

        bool found = false;
        for (auto& item : itemList) {
            if (item.itemName == itemName) {
                cout << "Enter new quantity: ";
                cin >> item.quantity;
                cin.ignore();
                cout << "Item updated successfully.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Item not found in the inventory.\n";
        }
    }

    void sortItems(list<Items>& itemList) {
        itemList.sort([](const Items& a, const Items& b) {
            return a.itemName < b.itemName;
        });
        cout << "Items sorted by name.\n";
    }
};

int main() {
    ItemManager manager;
    list<Items> itemList;
    char choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. View Items\n";
        cout << "4. Update Item\n";
        cout << "5. Sort Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the buffer

        switch (choice) {
            case '1':
                manager.addItem(itemList);
                break;
            case '2':
                manager.removeItem(itemList);
                break;
            case '3':
                manager.viewItems(itemList);
                break;
            case '4':
                manager.updateItem(itemList);
                break;
            case '5':
                manager.sortItems(itemList);
                manager.viewItems(itemList);
                break;
            case '6':
                cout << "Exiting...\n";
                break;
            default:
                cerr << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != '6');

    return 0;
}
