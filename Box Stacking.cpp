#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
//this structure contains the variables for the dimensions of a box ie, length, breadth and height
struct box
{
    int l,b,h;
};
 
//comparison function used for sorting of all the boxes based on their base area
bool compare(box one, box two)
{
    return one.l*one.b < two.l*two.b;
}
 
int boxStacking(vector<box> boxes, int n)
{
    int i,j;
 
    //vector to store all the results
    vector<int> lis(3*n);
 
    //lis[i]=maximum attainable height by including box i at the bottom
 
    //initialization
    for(i=0;i<3*n;i++)
        lis[i]=boxes[i].h;
 
    //implementing linear increasing subsequence approach 
    for(i=1;i<3*n;i++)
    {
        for(j=0;j<i;j++)
        {
            //if dimensions of box j are lesser than box i
            //box j can be placed on top of box i
            if(boxes[j].l<boxes[i].l && boxes[j].b<boxes[i].b)
            {
                if(lis[j]+boxes[i].h>lis[i])
                    lis[i]=lis[j]+boxes[i].h;
            }
        }
    }
 
    int maxHeight=lis[0];
 
    //now, choose the one which gives the maximum height
    for(i=1;i<3*n;i++)
    {
        if(lis[i]>maxHeight)
            maxHeight=lis[i];
    }
 
    return maxHeight;
}
 
int main()
{
    int n;
    int l,b,h;
 
    cout<<"Enter the number of boxes"<<endl;
    cin>>n;
 
    //there are n boxes
    //but a box can be rotated and can further give more boxes
    //so, we will be storing dimensions of 3*n boxes by including the dimensions of rotated boxes as well
    vector<box> boxes(3*n);
 
    for(int i=0;i<3*n;i++)
    {
        cout<<"Enter the dimensions of box (length,breadth,height)  ";
        cin>>l>>b>>h;
        boxes[i].l=min(b,h);
        boxes[i].b=max(b,h);
        boxes[i].h=l;
 
        i++;
 
        boxes[i].l=min(l,h);
        boxes[i].b=max(l,h);
        boxes[i].h=b;
 
        i++;
 
        boxes[i].l=min(l,b);
        boxes[i].b=max(l,b);
        boxes[i].h=h;
 
    }
 
    //sort the boxes based on the base area (l*b)
    sort(boxes.begin(),boxes.end(),compare);
 
    cout<<"Longest achievable height by stacking the boxes is "<<endl;
    cout<<boxStacking(boxes,n);
 
    cout<<endl;
    return 0;
}