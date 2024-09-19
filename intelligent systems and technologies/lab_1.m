clear, net = newp ([-4 4;-4 4], 2);
net.IW {1,1} = [-1 1; -3 4];
net.b {1} = [1; 2];
p1 = [4; 4];
a1 = sim(net,p1)
p2 = [4; -4];
a2 = sim(net,p2)
gensim(net)
n=-5 : 0.1 : 5;
plot (n, tribas (n),'b+:');