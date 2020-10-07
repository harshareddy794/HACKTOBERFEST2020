#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left,*right;
};

struct node* add_element(struct node*ROOT,int element){
  //adds element to the tree
  if(ROOT==NULL){
    //create new node
    ROOT = malloc(sizeof(struct node));
    ROOT->data = element;
    ROOT->left = ROOT->right=NULL;
  }
  else if (element<(ROOT->data)){
    ROOT->left = add_element(ROOT->left,element);
  }
  else{
    ROOT->right = add_element(ROOT->right,element);
  }
  return ROOT;
}

int smallest_element(struct node *ROOT){
  //returns the smallest element of the tree
  if((ROOT->left)!=NULL)
    return smallest_element(ROOT->left);
  return ROOT->data;
}

int largest_element(struct node *ROOT){
  //returns the larges element of the tree
  if((ROOT->right)!=NULL)
    return largest_element(ROOT->right);
  return ROOT->data;
}

struct node *remove_element(struct node* ROOT, int element){
  //Removes element from the tree

  if(ROOT==NULL)//Element is not found
    return NULL;
  else if(element > (ROOT->data))//delete from right tree
    ROOT->right = remove_element(ROOT->right,element);
  else if(element < (ROOT->data))//delete from left tree
    ROOT->left = remove_element(ROOT->left,element);
  else{
    //this node is to be deleted

    if(ROOT->left != NULL && ROOT->right != NULL){
      //Root = smallest of right child
      ROOT->data = smallest_element(ROOT->right);
      ROOT->right = remove_element(ROOT->right,ROOT->data);
      return ROOT;
    }

    struct node* rm_root = ROOT;
    if(ROOT->left == NULL && ROOT->right == NULL)
      ROOT = NULL;
    else if(ROOT->left == NULL)
      ROOT=ROOT->right;
    else
      ROOT=ROOT->left;
    free(rm_root);
  }
  return ROOT;
}

int search_element(struct node *ROOT,int element,int root_level){
  //searches for element in ROOT tree. Returns rootLevel if found
  //if element is not found, return -1

  if(ROOT==NULL){
    //element not found
    return -1;
  }
  else if(element == (ROOT->data))
    return root_level;
  else if(element<(ROOT->data))
    return search_element(ROOT->left,element,root_level+1);
  else
    return search_element(ROOT->right,element,root_level+1);
}

void inorder_traversal(struct node *ROOT){
  //Traversal takes place as :left tree -> ROOT-> right tree
  if(ROOT == NULL) return;

  inorder_traversal(ROOT->left);
  printf("%d ",ROOT->data);
  inorder_traversal(ROOT->right);

}

void preorder_traversal(struct node *ROOT){
  //Traversal takes place as :ROOT -> left tree-> right tree
  if(ROOT == NULL) return;

  printf("%d ",ROOT->data);
  inorder_traversal(ROOT->left);
  inorder_traversal(ROOT->right);

}

void postorder_traversal(struct node *ROOT){
  //Traversal takes place as :left tree-> right tree -> ROOT
  if(ROOT == NULL) return;

  inorder_traversal(ROOT->left);
  inorder_traversal(ROOT->right);
  printf("%d ",ROOT->data);

}

struct node* delete_tree(struct node* ROOT){
  if(ROOT != NULL){
    ROOT->left = delete_tree(ROOT->left);
    ROOT->right = delete_tree(ROOT->right);
    free(ROOT);
  }
  return NULL;
}

void main(){
  printf("Enter the size of the tree [number of elements] : ");
  int size,element;
  scanf("%d",&size );

  struct node* ROOT=NULL;
  for(int i=0;i<size;i++){
    printf("Enter the %d the element : ",i+1);
    scanf("%d",&element);
    ROOT = add_element(ROOT,element);
  }

  printf("The smallest element of the tree is %d \n",smallest_element(ROOT));
  printf("The largest element of the tree is %d \n",largest_element(ROOT));

  printf("\nTranversal");
  printf("\nInOrderTraversal : ");inorder_traversal(ROOT);
  printf("\nPreOrderTraversal : ");preorder_traversal(ROOT);
  printf("\nPostOrderTraversal : ");postorder_traversal(ROOT);

  printf("\nEnter a element to remove : ");
  scanf("%d",&element);
  ROOT = remove_element(ROOT,element);
  printf("\nInOrderTraversal after doing the remove operation \n");
  inorder_traversal(ROOT);

  printf("\nEnter a element to search : ");
  scanf("%d",&element);
  int level = search_element(ROOT,element,0);
  if(level == -1)
    printf("Element not found\n");
  else
    printf("Element found at %d level\n",level);

  //destroy the tree
  ROOT = delete_tree(ROOT);
}
