x <- c(1, 5, 4, 9, 0)
typeof(x)
length(x)
x <- c(1, 5.4, TRUE, "hello")
typeof(x)

message("")
message("Define a vector using the ':' operator.")
message("Note the difference between the types of x and x1.")
x1 <- 1:7; x1; typeof(x1)
y1 <- 2:-2; y1

message("")
message("Define a vector by specifying a sequence.")
x2 <- seq(1, 3, by=0.2)          # specify step size
print(x2)
y2 <- seq(1, 7, length.out=6)    # specify length of the vector
y2
