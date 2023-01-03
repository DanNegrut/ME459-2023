someFunction <- function(a) {
  my_list <- list("color" = "red", "size" = a, "shape" = "square")
  a <- a + 1
  print("Here's the new value of a, inside the function:")
  print(a)
  return(my_list)
}


fiboPrint <- function(nterms) {
  # first two terms
  n1 = 0
  n2 = 1
  count = 2
  if (nterms == 1) {
    print("Fibonacci sequence:")
    print(n1)
  } else {
    print("Fibonacci sequence:")
    print(n1)
    print(n2)
    while (count < nterms) {
      nth = n1 + n2
      print(nth)
      # update values
      n1 = n2
      n2 = nth
      count = count + 1
    }
  }
}
# take input from the user
#nterms = as.integer(readline(prompt="How many terms? "))
#fiboPrint(nterms)
