class Test{
private:
    int ele;
    Test * next;
    int ID;
public:
    Test();
    Test(int, Test *);
    int getElement();
    Test * getNext();
    int getID();
};
