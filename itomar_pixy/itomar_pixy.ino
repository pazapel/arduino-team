#include <Pixy2.h>
#define constant 0.1
#define minArea 0.8
#define maxArea 1.2
#define minSize 2

// This is the main Pixy object 
Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  //Serial.print("Starting...\n");
  pixy.init();
}

void merge(int *Arr, int start, int mid, int end) {
  int temp[end - start + 1];
  int i = start, j = mid+1, k = 0;
  while(i <= mid && j <= end) {
    if(pixy.ccc.blocks[Arr[i]].m_x <= pixy.ccc.blocks[Arr[j]].m_x) {
      temp[k] = Arr[i];
      k++; i++;
    }
    else {
      temp[k] = Arr[j];
      k++; j++;
    }
  }
  while(i <= mid) {
    temp[k] = Arr[i];
    k++; i++;
  }
  while(j <= end) {
    temp[k] = Arr[j];
    k++; j++;
  }
  for(i = start; i <= end; i += 1) {
    Arr[i] = temp[i - start];
  }
}

void mergeSort(int *Arr, int start, int end) {

  if(start < end) {
    int mid = (start + end) / 2;
    mergeSort(Arr, start, mid);
    mergeSort(Arr, mid+1, end);
    merge(Arr, start, mid, end);
  }
}

int checkSizeOfBlock(int *Blocks, int numBlocks)
{
  int i,sizeOfArr = 0;
  for(i = 0; i < numBlocks; i++)
  {
    if (pixy.ccc.blocks[i].m_width/pixy.ccc.blocks[i].m_height < minSize)
    {
      Blocks[sizeOfArr]=i;
      sizeOfArr++;
    }
  }
  return sizeOfArr;
}

void sendToRoborio(int *Blocks, int arrSize)
{
  int i;
  for (i=0; i<arrSize-1; i++)
   {
     Serial.print(Blocks[i]);
     Serial.print(" ");
     if (abs(pixy.ccc.blocks[Blocks[i]].m_y - pixy.ccc.blocks[Blocks[i+1]].m_y) < constant * abs(pixy.ccc.blocks[Blocks[i]].m_x - pixy.ccc.blocks[Blocks[i+1]].m_x) && minArea < (pixy.ccc.blocks[Blocks[i]].m_width * pixy.ccc.blocks[Blocks[i]].m_height)/(pixy.ccc.blocks[Blocks[i+1]].m_height * pixy.ccc.blocks[Blocks[i+1]].m_width) && (pixy.ccc.blocks[Blocks[i]].m_width * pixy.ccc.blocks[Blocks[i]].m_height)/(pixy.ccc.blocks[Blocks[i+1]].m_height * pixy.ccc.blocks[Blocks[i+1]].m_width) < maxArea)
     {
       /* Serial.print("block");
       Serial.print(ToSort[i+1]);
       Serial.print(": "); 
       pixy.ccc.blocks[ToSort[i+1]].print(); */
       Serial.print(pixy.ccc.blocks[Blocks[i+1]].m_x);
       Serial.print(" ");
       Serial.println(pixy.ccc.blocks[Blocks[i+1]].m_y);      
     }
   }
   Serial.print("// ");
}

void loop()
{ 
  int sizeOfArr;
  int numBlocks = pixy.ccc.getBlocks();
  int Blocks[numBlocks];
  // If w/h < 0.7 than +1 to j and +1 to i. else add one to i. after, ToSort empty values slots are written as -1 
  if (numBlocks)
  {
   sizeOfArr = checkSizeOfBlock(Blocks, numBlocks);
   mergeSort(Blocks,0,sizeOfArr);
   sendToRoborio(Blocks,sizeOfArr);
  }
}
