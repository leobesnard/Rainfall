#include <cstring>
#include <cstdlib>

class N {
private:
    char *annotation;
    int number;

public:
    N(int num) {
        number = num;
        annotation = nullptr;
    }
    
    virtual void operator+(N &other) {
    }
    
    void setAnnotation(char *str) {
        // VULNERABILITY: No bounds checking
        // The annotation buffer is only 4 bytes after the vtable pointer
        size_t len = strlen(str);
        memcpy(annotation, str, len);
    }
};

class N1 : public N {
public:
    N1(int num) : N(num) {}
    
    // Override the operator+
    virtual void operator+(N &other) override {
        // In a real implementation, this might do something with the other object
    }
};

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        exit(1);
    }
    
    // Create two objects of type N
    N *obj1 = new N(5);
    N *obj2 = new N(6);
    
    // Allocate memory for annotations
    obj1->annotation = new char[100]; 
    obj2->annotation = new char[100];
    
    // Set the annotation of the first object using the command-line argument
    // VULNERABILITY: This can overflow and corrupt the second object's vtable
    obj1->setAnnotation(argv[1]);
    
    // Call the virtual function (operator+) on the second object
    // If the vtable is corrupted, this will jump to an attacker-controlled address
    *obj2 + *obj1;
    
    return 0;
}
