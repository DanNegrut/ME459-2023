
Wingcrd <- c(59, 55, 53.5, 55, 52.5, 57.5, 53, 55)
Tarsus <- c(22.3, 19.7, 20.8, 20.3, 20.8, 21.5, 20.6, 21.5)
Head <- c(31.2, 30.4, 30.6, 30.3, 30.3, 30.8, 32.5, NA)
Wt <- c(9.5, 13.8, 14.8, 15.2, 15.5, 15.6, 15.6, 15.7) 
BirdData <- cbind(Wingcrd, Tarsus, Head, Wt)
write.table(BirdData, "BirdData.csv", sep=",")
BirdDF <- read.csv("BirdData.csv", header=TRUE)
plot(BirdDF)

head(cars)

plot(
  cars$speed,
  cars$dist,
  main = "A Title",
  xlab = "The Speeds",
  ylab = "The Distances",
  col = "steel blue"
)

plot(cars)

par(new = TRUE)
plot(lowess(cars),
     type = "l",
     col = "red")


par(mfrow = c(2, 2))
plot(cars, type = "p")
plot(cars, type = "l")
plot(cars, type = "h")
plot(cars, type = "s")


png(filename = "mess.png")
plot(mtcars)
dev.off()
