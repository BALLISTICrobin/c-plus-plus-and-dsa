#include"dsa_doubleEndedQueue.cpp"
void findNegative(Queue<int> &q){
    //pending
}


int main(int argc, char const *argv[])
{
    Queue<int> q1;
    for(int i=0; i<q1.size; i++){
        int data;
        cin>>data;
        q1.enqueBack(data);
    }
    findNegative(q1);
    return 0;
}
