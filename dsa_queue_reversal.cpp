#include"dsa_doubleEndedQueue.cpp"


void reverse_queue(Queue<int> &q){
    if(q.isEmpty()){
        return;

    }
    int a = q.Front();
    q.dequeFront();
    reverse_queue(q);
    q.enqueBack(a);

}

int main(int argc, char const *argv[])
{
    
    Queue<int> q1;
    for(int i=0; i<q1.size; i++){
        int data;
        cin>>data;
        q1.enqueBack(data);
    }
    reverse_queue(q1);
    q1.display();
    return 0;
}

