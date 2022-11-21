#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n; // frame we required
int page[N], mark[N]; // pages whch we r going to give..and mark
int frame_size;
void fifo_replacement(void){
    queue<int>Q;
    int hits=0, fault = 0;
    for(int i=0; i<n;i++){
        if(mark[page[i]]==true){
            hits++;
        }
        else{
            Q.push(page[i]);
            mark[page[i]]=true;
            if(Q.size()>frame_size){
                int p = Q.front();
                mark[p]=false;
                Q.pop();
            }
            fault++;

        }

    }

    cout<<"Number of fault: "<<fault<<endl;
    cout<<"Number of hits: "<<hits<<endl;
    float rt_fault = (float(fault)/n)*100;
    float rt_hit = (float(hits)/n)*100;

    cout<<"Ratio of page fault: "<<rt_fault<<endl;
    cout<<"Ratio of HIT: "<<rt_hit<<endl;
}

int main(){
    cout<<"Enter the frame size: ";
    cin>>frame_size;
    cout<<"Enter the refereence string length: ";
    cin>>n;
    cout<<"Enter numbers ";
    for(int i=0;i<n;i++){
        cin>>page[i];

    }

    fifo_replacement();

}
