<html>
  <body>
    <script>
      class Node { //defining a JavaScript class
          constructor(data) { //constructor method
              this.data = data; //data value of the node
              this.next = null; //link of the next node
          }
      }
      const head = new Node(12); //creating a node
 function displayTime(){
    let time = new Date();
    console.log(time);
    document.getElementById('time').innerHTML=time;
    }
    setInterval(displayTime , 1000)

    </script>
  </body>
</html>
