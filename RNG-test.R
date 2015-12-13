uni_seq = read.csv("./tmp/uniform-seq.csv", header=FALSE)
hist(as.numeric(uni_seq[1,]), breaks=70, col = "lightblue", border = "blue", xlab = "X value", main = "Histogram of 100,000 X~U(0,1) values")

poisson_seq = read.csv("./tmp/poisson-seq.csv", header=FALSE)
hist(as.numeric(poisson_seq[1,]), breaks=70, col = "lightblue", border = "blue", xlab = "X value", main = "Histogram of 100,000 X~P(lambda) values")

exp_seq = read.csv("./tmp/exp-seq.csv", header=FALSE)
hist(as.numeric(exp_seq[1,]), breaks=70, col = "lightblue", border = "blue", xlab = "X value", main = "Histogram of 100,000 X~E(mu) values")
