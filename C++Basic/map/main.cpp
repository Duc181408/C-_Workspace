#include <iostream>
#include <stdexcept>

enum Color { RED, BLACK };

template<typename KeyType, typename ValueType>
class OrderMap {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Color color;
        Node* left;
        Node* right;
        Node* parent;

        Node(const KeyType& k, const ValueType& v, Color c = RED) : key(k), value(v), color(c), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // Hàm rotateRight thực hiện phép xoay phải tại nút x
    void rotateRight(Node* x) {
        // Lưu trữ con trỏ tới nút con trái của nút x vào y
        Node* y = x->left;
        
        // Thực hiện việc di chuyển con trỏ từ nút con phải của y sang nút con trái của x
        x->left = y->right;
        
        // Nếu nút con phải của y tồn tại, cập nhật con trỏ parent của nút con phải đó là x
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        
        // Di chuyển con trỏ parent của y sang nút parent của x
        y->parent = x->parent;
        
        // Nếu nút x là nút gốc của cây, cập nhật nút gốc mới là y
        if (x->parent == nullptr) {
            root = y;
        } 
        // Nếu nút x không phải là nút gốc và nút x là con phải của nút cha
        else if (x == x->parent->right) {
            // Cập nhật con trỏ của nút cha sao cho nút phải của nút cha trỏ tới y
            x->parent->right = y;
        } 
        // Nếu nút x không phải là nút gốc và nút x là con trái của nút cha
        else {
            // Cập nhật con trỏ của nút cha sao cho nút trái của nút cha trỏ tới y
            x->parent->left = y;
        }
        
        // Cập nhật con trỏ từ nút phải của y sang x
        y->right = x;
        
        // Cập nhật con trỏ parent của x để trỏ tới y
        x->parent = y;
    }


// Hàm fixInsertion để sửa lỗi vi phạm các thuộc tính của cây đỏ đen sau khi chèn một nút mới
void fixInsertion(Node* z) {
    // Lặp lại quá trình sửa lỗi cho đến khi không còn vi phạm hoặc nút z là gốc của cây
    while (z != root && z->parent->color == RED) {
        // Nếu nút cha của nút z là nút trái của nút của nó
        if (z->parent == z->parent->parent->left) {
            // Lưu trữ con trỏ tới nút em của nút cha (nút kế bên phải của nút của nó)
            Node* y = z->parent->parent->right;
            
            // Nếu nút em của nút cha là màu đỏ
            if (y != nullptr && y->color == RED) {
                // Đổi màu nút cha và nút em của nút cha thành đen
                z->parent->color = BLACK;
                y->color = BLACK;
                // Đổi màu nút cha của nút cha thành đỏ
                z->parent->parent->color = RED;
                // Di chuyển con trỏ z lên nút cha của nút cha (lớp cha của lớp cha)
                z = z->parent->parent;
            } else {
                // Nếu nút em của nút cha không phải là màu đỏ hoặc không tồn tại
                // và nút z là nút phải của nút cha
                if (z == z->parent->right) {
                    // Di chuyển con trỏ z lên nút cha
                    z = z->parent;
                    // Thực hiện phép xoay trái tại nút cha
                    rotateLeft(z);
                }
                // Đổi màu nút cha của nút z thành đen
                z->parent->color = BLACK;
                // Đổi màu nút cha của nút cha thành đỏ
                z->parent->parent->color = RED;
                // Thực hiện phép xoay phải tại nút cha của nút z
                rotateRight(z->parent->parent);
            }
        } 
        // Nếu nút cha của nút z là nút phải của nút của nó
        else {
            // Lưu trữ con trỏ tới nút em của nút cha (nút kế bên trái của nút của nó)
            Node* y = z->parent->parent->left;
            // Nếu nút em của nút cha là màu đỏ
            if (y != nullptr && y->color == RED) {
                // Đổi màu nút cha và nút em của nút cha thành đen
                z->parent->color = BLACK;
                y->color = BLACK;
                // Đổi màu nút cha của nút cha thành đỏ
                z->parent->parent->color = RED;
                // Di chuyển con trỏ z lên nút cha của nút cha (lớp cha của lớ  p cha)
                z = z->parent->parent;
            } else {
                // Nếu nút em của nút cha không phải là màu đỏ hoặc không tồn tại
                // và nút z là nút trái của nút cha
                if (z == z->parent->left) {
                    // Di chuyển con trỏ z lên nút cha
                    z = z->parent;
                    // Thực hiện phép xoay phải tại nút cha
                    rotateRight(z);
                }
                // Đổi màu nút cha của nút z thành đen
                z->parent->color = BLACK;
                // Đổi màu nút cha của nút cha thành đỏ
                z->parent->parent->color = RED;
                // Thực hiện phép xoay trái tại nút cha của nút z
                rotateLeft(z->parent->parent);
            }
        }
    }
    // Đảm bảo rằng nút gốc của cây luôn là màu đen
    root->color = BLACK;
}


    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    Node* minimum(Node* x) {
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    void deleteFixup(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    OrderMap() : root(nullptr) {}

    ~OrderMap() {
        // Delete all nodes in the tree (post-order traversal)
        while (root != nullptr) {
            if (root->left != nullptr) {
                deleteFixup(root->left);
            }
            if (root->right != nullptr) {
                deleteFixup(root->right);
            }
            delete root;
            root = nullptr;
        }
    }

    void insert(const KeyType& key, const ValueType& value) {
        Node* z = new Node(key, value);                          // tạo node mới
        Node* y = nullptr;                                       // tạo node tạm y
        Node* x = root;                                          // chọc x đến head

        while (x != nullptr) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        z->color = RED;
        fixInsertion(z);
    }

    ValueType& operator[](const KeyType& key) {
        Node* current = root;
        while (current != nullptr) {
                        if (key == current->key) {
                return current->value;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        throw std::out_of_range("Key not found");
    }
};

int main() {
    OrderMap<int, int > myMap;
    myMap.insert(5, 100);
    myMap.insert(7, 20);
    myMap.insert(3, 30);
    myMap.insert(9, 100);
    myMap.insert(11,20);
    myMap.insert(1,25);
    myMap.insert(13,20);
    myMap.insert(14,20);
    myMap.insert(15,20);
    myMap.insert(16,20);


    std::cout << "Value of key 5: " << myMap[5] << std::endl;
    std::cout << "Value of key 7: " << myMap[7] << std::endl;
    std::cout << "Value of key 3: " << myMap[3] << std::endl;

    try {
        std::cout << "Value of key 10: " << myMap[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

