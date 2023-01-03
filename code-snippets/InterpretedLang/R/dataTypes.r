a <- c(1,2,5.3,6,-2.9,4)                # numeric vector
b <- c("one","two","three")             # character vector
c <- c(TRUE,TRUE,TRUE,FALSE,TRUE,FALSE) #logical vector

a[c(2,5)] # 2nd and 5th elements of vector



# Matrices...
y<-matrix(1:20, nrow=5,ncol=4)
y[,4] # 4th column of matrix
y[3,] # 3rd row of matrix
y[2:4,1:3] # rows 2,3,4 of columns 1,2,3

cells <- c(1,26,24,68)
rnames <- c("R1", "R2")
cnames <- c("C1", "C2")
mymatrix <- matrix(cells, nrow=2, ncol=2, byrow=TRUE, dimnames=list(rnames, cnames))

# Lists...
list_data <- list("Red", "Green", c(21,32,11), TRUE, 51.23, 119.1)
print(list_data)

# Create a list containing a vector, a matrix and a list.
list_data <- list(c("Jan","Feb","Mar"), 
                     matrix(c(3,9,5,1,-2,8), nrow = 2), 
                     list("green",12.3))

# Give names to the elements in the list.
names(list_data) <- c("1st Quarter", "A matrix", "Inner list")

# Access the first element of the list.
print(list_data[1])

# Access 3rd elem. - a list; all its elements will be printed
print(list_data[3])

# Access the list element using the name of the element.
print(list_data$`A matrix`)
