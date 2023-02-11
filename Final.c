/*y = number of elemnts in dataset
  i,k,j,b,c = loop variables
  z = variable for scanning values into data[]
  count = for counting frequency */
#include <stdio.h>
#include <math.h>
int y,k,z,l;
int i,j, count;
float var;
void sortasc(int *data);
void sortdes(int *data,int *rev);
void frequency(int *data,int (*group)[2]);
void histogram(int *data,int (*group)[2]);
void mean(int *data);
void median(int *data);
void mode(int (*group)[2]);
void variance(int *data);
void stdeviation(int *data);

int main(){
  puts("Welcome to the Statistics Module");
  printf("Enter the number of elements in dataset:");
  scanf("%d",&y);
  int data[y];
  int rev[y];
  int group[y][2];
  for(k=0;k<y;k++){
    printf("Enter the element:");
    scanf("%d",&z);
    data[k]=z;
    rev[k]=z;
  }

  for (i=0;i<y;i++){
    count=0;
    for (j=0;j<y;j++){
      if (data[i]==data[j]){
        count++;
        for(l=0;l<i;l++){
          if (data[i]==group[l][0]){
            group[i][0]=0;
            group[i][1]=0;
            goto here;
          }
      }
        group[i][0]=data[i];
        group[i][1]=count;
        here:
          continue;
      }
    }
  }
  printf("What would you like to do?\n1)Ascending Order\n2)Descending Order\n3)Frequency Table\n4)Histogram\n5)Mean value\n6)Median value\n7)Mode value\n8)Variance\n9)Step Deviation\n10)All of the above\n11)Enter new set\n12)Exit\n");
  int q;
start:
  printf("Enter your choice : ");
  scanf("%d",&q);
  switch (q) {
    case 1:
      sortasc(data);
      goto start;
      break;
    case 2:
      sortdes(data,rev);
      goto start;
      break;
    case 3:
      frequency(data,group);
      goto start;
      break;
    case 4:
      histogram(data,group);
      goto start;
      break;
    case 5:
      mean(data);
      goto start;
      break;
    case 6:
      median(data);
      goto start;
      break;
    case 7:
      mode(group);
      goto start;
      break;
    case 8:
      variance(data);
      goto start;
      break;
    case 9:
      stdeviation(data);
      goto start;
      break;
    case 10:
      sortasc(data);
      sortdes(data,rev);
      frequency(data,group);
      histogram(data,group);
      mean(data);
      median(data);
      mode(group);
      variance(data);
      stdeviation(data);
      goto start;
      break;
    case 11:
      main();
      break;
    case 12:
      goto end;
      break;
  }
  end:
    return 0;
}
///////////////////////////////////////////
void sortasc(int *data){
  printf("Array in ascending order is :\n");
  int b,c;
  for (b=1;b<y;b++){
    for (c=0;c<(y-1);c++){
      if (data[c] > data[c + 1]) {
        int h = data[c];
        data[c] = data[c + 1];
        data[c + 1] = h;
      }
    }
  }
  for (c=0;c<y;c++){
    printf("%4d",data[c]);
  }
  printf("\n");
}
//////
void sortdes(int *data,int *rev){
  int f,g,s;
  for (f=0;f<y;f++){
    for (g=f+1;g<y;g++){
      if (rev[f]<rev[g]){
        s=rev[f];
        rev[f]=rev[g];
        rev[g]=s;
      }
    }
  }
  printf("Array in descending order is:\n");
  for (f=0;f<y;f++){
    printf("%4d",rev[f]);
  }
  printf("\n");
}
///////
void frequency(int *data,int (*group)[2]){
  printf("The freuency table is:\n ");
  printf("Element Frequency\n");
  int i,j;
  for (i=0;i<y;i++){
    if (group[i][1]==0){
      continue;
    }
    for (j=0;j<2;j++){
      printf("%7d",group[i][j]);
    }
    printf("\n");
  }
}
//////
void histogram(int *data,int (*group)[2]){
  printf("%s%13s%12s\n", "Element", "Value", "Histogram");
  int b,c;
  for (b = 0; b < y; b++) {
    if (group[b][1]==0){
      continue;
    }
    printf("%7u%13d", group[b][0], group[b][1]);
    for (int c = 1; c <= group[b][1]; c++) {
      printf("%4s", "*");
      }
    puts("");
  }
}
/////
void mean(int *data){
  float sum=0;
  float mean;
  for (i=0;i<y;i++){
    sum=sum+data[i];
  }
  mean=sum/y;
  printf("The sum of the elements is : %f\n",sum);
  printf("The mean of the dataset is = %f\n",mean);
}
///////
void median(int *data){
  int b,c;
  for (b=1;b<y;b++){
    for (c=0;c<(y-1);c++){
      if (data[c] > data[c + 1]) {
        int h = data[c];
        data[c] = data[c + 1];
        data[c + 1] = h;
      }
    }
  }
  int t;
  float s;
  if (y%2!=0){
    t=(y+1)/2;
    printf("The median value is : %d\n",data[t-1]);
  }
  else{
    t=y/2;
    s=(data[t-1]+data[t])/2;
    printf("The median value is : %f\n",s);
  }
}
///////
  void mode(int (*group)[2]){
    int m=group[0][1];
    int u;
    for (i=0;i<y;i++){
      if (m<group[i][1]){
        m=group[i][1];
        u=i;
      }
    }
    printf("The mode is %d and its frequency is %d\n",group[u][0],m);
  }
  //////
void variance(int *data){
    int sum=0;
    float vsum=0;
    float mean;
    for (i=0;i<y;i++){
      sum=sum+data[i];
    }
    mean=sum/y;
    for (i=0;i<y;i++){
      vsum=vsum+((mean-data[i])*(mean-data[i]));
    }
    var=vsum/y;
    printf("The variance is : %f\n",var);
  }
  /////////
void stdeviation(int *data){
    int sum=0;
    float vsum=0;
    float mean;
    for (i=0;i<y;i++){
      sum=sum+data[i];
    }
    mean=sum/y;
    for (i=0;i<y;i++){
      vsum=vsum+((mean-data[i])*(mean-data[i]));
    }
    var=vsum/y;
    float stv;
    stv=sqrt(var);
    printf("The standard deviation is : %f\n",stv);
  }
