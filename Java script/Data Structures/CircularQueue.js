class CircularQueue {
   constructor(size) {
    
     this.queue = [];
     this.read = 0;
     this.write = 0;
     this.max = size - 1;
     this.count=0;

     while (size > 0) {
        this.queue.push(null);
        size--;
     }
   }
  checkEmpty(){
   var count=0;
      for(let i=0;i<=this.max;i++){
        if(this.queue[i]==null){
          count++;
        }
      }
    if(count==this.max+1){
      return true;
    }
    return false;
  }
  checkFull(){
      var count=0;
      for(let i=0;i<=this.max;i++){
        if(this.queue[i]==null){
          count++;
        }
      }
     if(count>0) {
     return false;
    }
    return true;
   }
  
   print() {
     return this.queue;
   }

   enqueue(item) {
    if(!this.checkFull()){
       this.queue[this.write]=item;
       this.write=(this.write+1)%(this.max+1);
       }
      } 
   
  
   dequeue() {
     if(!this.checkEmpty()){
       let val=this.queue[this.read];
       this.queue[this.read]=null;
       this.read=(this.read+1)%(this.max+1);
       return val;
     }
    else return null;
   }
}
