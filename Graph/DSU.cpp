class dsu{
    vector<int> parent,size,rank;

    dsu(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findPar(int node){

        if(node == parent[node])return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionSize(int u, int v){
        int paru = findPar(u);
        int parv = findPar(v);
        if(paru == parv)return;
        if(size[paru] > size[parv]){
            size[paru] += size[parv];
            parent[parv] = paru;
        }else{
            size[parv] += size[paru];
            parent[paru] = parv;
        }
    }

    void unionRank(int u, int v){
        int paru = findPar(u);
        int parv = findPar(v);
        if(paru == parv)return;

        if(rank[paru] == rank[parv]){
            parent[paru] = parv;
            rank[paru]++;
        }else if(rank[paru] < rank[parv]){
            parent[paru] = parv;
        }else{
            parent[parv] = paru;
        }
    }
};
