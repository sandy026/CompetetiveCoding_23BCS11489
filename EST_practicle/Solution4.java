
class Solution4 {
    public void floydWarshall(int[][] dist) {
        int n = dist.length;
        int INF = (int)1e8;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    // avoid overflow with INF
                    if (dist[i][k] == INF || dist[k][j] == INF) continue;

                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}