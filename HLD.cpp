//need LCA template to answer tree queries
namespace HLD{
    int sub[M], par[M], depth[M];
    int head[M], chain[M], pos[M];
    int cur_pos, cur_chain;


    void dfs(int u, int p=0, int h=0){
        sub[u] = 1;
        par[u] = p;
        depth[u] = h;
        for(auto v : g[u]){
            if(v != p){
                dfs(v, u, h+1);
                sub[u] += sub[v];
            }
        }
    }

    void decompose(int u){
        int c = -1;
        for(auto v : g[u]){
            if(v != par[u] and sub[v] >= sub[u]/2) c = v;
        }
        
        if(head[u] == 0){
            head[u] = u;
            chain[u] = ++cur_chain;
        }else{
            chain[u] = chain[head[u]];

        }
        pos[u] = ++cur_pos;
        //set value here
        if(c != -1){
            head[c] = head[u];
            decompose(c);
        }
        for(auto v : g[u]){
            if(v != par[u] and v != c){
                decompose(v);
            }
        }
    }

    void HLD(int root, int n){
        cur_pos = cur_chain = 0;
        for(int i=1; i<=n; i++){
            sub[i] = par[i] = depth[i] = head[i] = chain[i] = pos[i] = 0;
        }
        dfs(root);
        decompose(root);
    }

    int anc_query(int u, int v){ //u is ancestor of v

        int ret = 0;
        while(1){   
            int L = pos[head[v]], R = pos[v];
            if(depth[u] >= depth[head[v]]){
                //include query(pos[u], R) if vertex values, query(pos[u]+1, R) if edge values
                break;
            }
            //include query(L, R)
            v = par[head[v]];
        }
        return ret;
        
    }

    int tree_query(int x, int y){
        int L = LCA::LCA(x, y);
        int ret;    //combine anc_query(L, x) and (L, y);
        return ret;
    }
}
