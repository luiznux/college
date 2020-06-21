#include "map.cpp"

int main(){

    Value *little_car = new Value("BMW", "Rosa-bebe", 2007);
    Node node_little_car("AXW-1011",little_car);
    Map carao;
    carao.insertMap(&node_little_car);

    return 0;
}
