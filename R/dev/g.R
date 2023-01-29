cars <- c(1,3,6,9)
pdf("cars.pdf")
plot(cars, type="o", pch=19, col="red", lwd=2, lty=2, xlab="Time", ylab="Cars", main="Cars over time")
dev.off()


