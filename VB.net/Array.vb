Live Demo
Module arrayApl
   Sub Main()
      Dim n(10) As Integer ' n is an array of 11 integers '
      Dim i, j As Integer
      ' initialize elements of array n '         
      
      For i = 0 To 10
          n(i) = i + 100 ' set element at location i to i + 100 
      Next i
      ' output each array element's value '
      
      For j = 0 To 10
          Console.WriteLine("Element({0}) = {1}", j, n(j))
      Next j
      Console.ReadKey()
   End Sub
End Module