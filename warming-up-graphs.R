library(zoo)

clock = read.csv("./1/clock1.csv", header=FALSE)[1:998]
simulation_results1 = read.csv("./1/customer-amount1.csv", header=FALSE)
simulation_results2 = read.csv("./1/customer-amount2.csv", header=FALSE)
simulation_results3 = read.csv("./1/customer-amount3.csv", header=FALSE)
simulation_results4 = read.csv("./1/customer-amount4.csv", header=FALSE)
simulation_results5 = read.csv("./1/customer-amount5.csv", header=FALSE)


mean <- as.numeric(colMeans(rbind(simulation_results1[1:1000], simulation_results2[1:1000], simulation_results3[1:1000], simulation_results4[1:1000], simulation_results5[1:1000]), na.rm=TRUE))
mean_averaged <- rollmean(c(mean), 3, fill = NA)[1:998]

write.table(mean_averaged, file = "averaged1.csv", dec=".")
