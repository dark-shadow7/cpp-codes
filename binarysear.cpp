#include<iostream>
#include<vector>
using namespace std;

/*bool binary(int *a,int n,int first,int last)
{
   if(last>=1)
   {
       int mid=(first+last)/2;
       if(a[mid]==n)
        return true;
       if(a[mid]>n)
        return binary(a,n,first,mid-1);
       return binary(a,n,mid+1,last);
   }

}*/
bool binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return true;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return false;
}
int main()
{
    int n;
  int v[10];
  for(int i=0;i<10;i++)
  {
      v[i]=i*i;
  }
  cout<<"enter the element you want to search--";
  cin>>n;
  if(binarySearch(v,0,9,n))
  {cout<<"\nfound";}
  else
    cout<<endl<<"not found";
}
