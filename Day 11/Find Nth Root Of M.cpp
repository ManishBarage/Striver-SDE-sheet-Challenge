int NthRoot(int n, int m) {
  
 int end = m;
 int start =1;
 

 while(start <=end)
 {
   int mid = start +(end-start)/2;
   
   if(pow(mid,n) > m)
   {
     end = mid-1;
   }
   else if(pow(mid,n) == m)
   {
     return mid;
   }
   else
   {
     start = mid+1;
   }
 }

 return -1;
 
}