# Heap Implementation

A tool to observe heap behaviors. It contains three types of heaps : Max-Heap, Min-Heap, Maximum 3-Heap.  
For Min-Heap and Max-Heap, it can be toggled to invert one (max -> min / min -> max), and can delete the root node.  
For Maximum 3-Heap node, it can delete the root node.  

## Examples

>```16 5 8 10 12 1 14 15 3 11 9 7 4 13 2```  
>Entering heap type - [1]Max-Heap  [2]Min-Heap  [3]Maximum 3-Heap : `1`  
>Current heap :  
>16  
>15 14  
>12 11 7 13  
>5 3 10 9 1 4 8 2  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>15  
>12 14  
>5 11 7 13  
>2 3 10 9 1 4 8  
>
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>14  
>12 13  
>5 11 7 8  
>2 3 10 9 1 4  
>
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>13  
>12 8  
>5 11 7 4  
>2 3 10 9 1  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`1`  
>1  
>3 2  
>4 9 5 7  
>13 8 11 10 12  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`1`  
>13  
>11 12  
>8 10 7 5  
>1 4 3 9 2  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`3`  
>  
>Process finished with exit code 0 
---
>```16 5 8 10 12 1 14 15 3 11 9 7 4 13 2```  
>Entering heap type - [1]Max-Heap  [2]Min-Heap  [3]Maximum 3-Heap : `2`  
>Current heap :  
>1  
>3 2  
>10 9 5 4  
>16 15 12 11 8 7 14 13  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>2  
>3 4  
>10 9 5 13  
>16 15 12 11 8 7 14  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>3  
>9 4  
>10 11 5 13  
>16 15 12 14 8 7  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>4  
>9 5  
>10 11 7 13  
>16 15 12 14 8  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`1`  
>16  
>15 11  
>13 14 8 7  
>4 10 9 12 5  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`2`  
>15  
>14 11  
>13 12 8 7  
>4 10 9 5  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`1`  
>4  
>5 8  
>10 7 14 11  
>15 12 13 9  
>  
>Enter behavior - [1]Toggle to min/max  [2]delete one node(min/max)  [3]exit:`3`  
>  
>Process finished with exit code 0  
---
>```16 5 8 10 12 1 14 15 3 11 9 7 4 13 2```  
>Entering heap type - [1]Max-Heap  [2]Min-Heap  [3]Maximum 3-Heap : `3`  
>Current heap :  
>16  
>14 15 10  
>13 1 12 8 3 11 9 7 4  
>5 2  
>  
>Enter behavior - [1]Delete one node(max)  [2]exit:`1`  
>15  
>14 11 10  
>13 1 12 8 3 2 9 7 4  
>5  
>  
>Enter behavior - [1]Delete one node(max)  [2]exit:`1`  
>14  
>13 11 10  
>5 1 12 8 3 2 9 7 4  
>  
>Enter behavior - [1]Delete one node(max)  [2]exit:`1`  
>13  
>12 11 10  
>5 1 4 8 3 2 9 7  
>  
>Enter behavior - [1]Delete one node(max)  [2]exit:`3`  
>  
>Process finished with exit code 0  

