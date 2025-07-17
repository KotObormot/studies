//https://monitorbank.ru/derevya-v-c/
#include <iostream>
using namespace std;
 
//объявление для нового узла дерева
struct node  { 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
   
//выделяет новый узел
struct node* newNode(int data) { 
    // объявить и выделить новый узел  
    struct node* node = new struct node();     
    node->data = data;    // Назначить данные этому узлу    
    // Инициализируйте левый и правый дочерние элементы как NULL 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
   
int main() { 
  /*создать корневой узел*/
    /*struct*/ node *rootNode = newNode(10);  
    cout << "General tree created is as follows:" << endl;
    cout << "\t\t\t " << rootNode->data << endl;
    cout << "\t\t\t "<< "/ " << "\\" << endl;
    rootNode->left  = newNode(20); 
    rootNode->right = newNode(30); 
    cout << "\t\t\t" << rootNode->left->data << "  " << rootNode->right->data;
    cout<<endl;
    rootNode->left->left = newNode(40);
    rootNode->left->right = newNode(50);
    cout << "\t\t\t" << "/ " << "\\" << endl;
    cout << "\t\t      " << rootNode->left->left->data << "  " << rootNode->left->right->data  << "\n";
    
    std::cout << rootNode->data 
              << " " << rootNode->left->data << " " << rootNode->right->data
              << " " << rootNode->left->left->data << "  " << rootNode->left->right->data  << "\n";

    if(rootNode->right->left != nullptr) {
        cout << "!! " << rootNode->right->left->data << " !!\n";
    } else {
        cout << "!! " << rootNode->right->left << " !!\n";
    }

    cout << rootNode->right->right << " ";
    rootNode->right->right = newNode(0);
    cout << rootNode->right->right << " " << "! " << rootNode->right->right->data << " !\n";

    delete rootNode;
return 0; 
}