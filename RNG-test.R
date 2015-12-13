mydata = read.csv("./tmp/uniform-seq.csv", header=FALSE)

hist(as.numeric(mydata[1,]), breaks=70, col = "lightblue", border = "blue", xlab = "X value", main = "Histogram of 100,000 U(0,1) values")
