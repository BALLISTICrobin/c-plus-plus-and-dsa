#include"listLL1.cpp"
//#include"listArr1.cpp"
// void reArrnage(Linkedlist &L1){
//     int count =0;
//     Node *reTail =L1.tail;
//     Node *reHead = L1.head;
//     while(count<L.length()/2){
//         Node *temp = L1.head->next;
//         L1.head->next  = L1.tail;
//         L1.tail->next = temp;
//         L1.head = temp;
       
//         L1.trav = L1.head;
//         while(L1.trav->next != L1.tail ){
//             L1.trav = L1.trav->next;
//         }
//         L1.tail = L1.trav;
//         count++;
//     }
//     L1.head = reHead;
// }

 
int main(int argc, char const *argv[])
{
    L.init();
    L.display();
    int len = L.size/2;
    for(int i=0;i<L.size/2; i++){
        L.moveToPos(i);
        
        cout<<L.getValue()<<" ";
        L.moveToPos(L.size-i-1);
         
        cout<<L.getValue()<<" ";
    }
    if(L.size%2!=0){
        L.moveToPos(len);
        cout<<L.getValue();
    } 
    cout<<endl;
    // reArrnage(L);
    // L.display();


    return 0;
}
