k= k%n if k> length of the linked list
if we rotate k time then last k nodes will be at front and the next of n-k th node will point to null
​
what we will do is that we will make a circular linked list and find out the n-k th node and  will point its next to NUll;
and its next as head