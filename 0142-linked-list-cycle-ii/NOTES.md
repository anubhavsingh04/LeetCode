loop hai ki nahi ckeck krne ke lie slow ek bar aur fast do bar chalao
agr fast ya fast ka agla null hua means loop nahi hai
nahi to slow ko head pr pahucha ke phir se fast aur slow jbtk barabar nahi hote tab tk ek ek bar chalao
// loop removal
void removeLoop(Node* head)
{
if(!head) return;
Node*slow=head,*fast=head;
while(fast && fast->next)
{
slow=slow->next;
fast=fast->next->next;
if(slow==fast) break;
}
if(fast==NULL || fast->next==NULL) return; // means loop nahi hai
slow=head;
while(slow!=fast)
{
slow=slow->next;
fast=fast->next;
}
// slow vali val pe loop hai
Node*prev=slow->next;
while(prev->next!=slow) prev=prev->next;
prev->next=NULL;
}