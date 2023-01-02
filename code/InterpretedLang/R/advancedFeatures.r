#This is an R comment
t.test(cars$speed, mu=12)

t.test(cars$speed, mu=12, alternative="less", conf.level=.99)


car.fit <- lm(dist ~ speed, cars)
summary(car.fit)
plot(car.fit)
plot( resid(car.fit) ~ speed , data=cars )
plot(cars$speed, cars$dist, xlab="distance", ylab="speed")
abline(car.fit, col="red")