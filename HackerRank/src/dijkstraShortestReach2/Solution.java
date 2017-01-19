package dijkstraShortestReach2;

import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;




public class Solution {


    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in, 100000000));

        short T = sc.nextShort();
        while (0 < (T--)) {
            short N = sc.nextShort();
            final Graph graph = new Graph((short) (N + 1));

            int M = sc.nextInt();
            while (0 < (M--)) {
                short x = sc.nextShort();
                short y = sc.nextShort();
                int r = sc.nextInt();

                graph.createEdge(x, y, r);
            }

            short s = sc.nextShort();
            final long[] result = dijkstra(s, graph);
            for (int i = 1; i < result.length; i++) {
                if (i == s) {
                    continue;
                }

                System.out.printf("%d ", (result[i] != 0) ? result[i] : -1);
            }

            System.out.println();
        }

        sc.close();
    }

    private static long[] dijkstra(final short startId, final Graph graph) {
        final long[] nodeDistances = new long[graph.nodes.length];
        // Arrays.fill(nodeDistances, Long.MAX_VALUE);
        // nodeDistances[startId] = 0;
        final boolean[] passedNodes = new boolean[graph.nodes.length];

        final Node startNode = graph.getNode(startId);
        final PriorityQueue<Pair> pool = new PriorityQueue<>();
        // final Comparator<Node> comparator = new Comparator<Node>() {
        // @Override
        // public int compare(Node o1, Node o2) {
        // return Long.compare(nodeDistances[o1.ix], nodeDistances[o2.ix]);
        // }
        // };
        // // final PriorityQueue<Node> pool = new PriorityQueue<>(graph.nodes.length, comparator);
        // final Set<Node> pool = new HashSet<>();
        pool.add(new Pair(0, startNode));
        short nodesInPool = 1;
        while (!pool.isEmpty() && (nodesInPool != 0)) {
            // final Node node = pool.poll();
            //final Node node = Collections.min(pool, comparator);
            //pool.remove(node);
            final Node node = pool.poll().node;
            if (passedNodes[node.ix]) {
                continue;
            }
            nodesInPool--;
            passedNodes[node.ix] = true;

            for (final Node neighbour : node.neighbours.keySet()) {
                // if (passedNodes[neighbour.ix]) {
                // continue;
                // }
                long candidate = nodeDistances[node.ix] + node.neighbours.get(neighbour);
                if (nodeDistances[neighbour.ix] == 0) {
                    nodeDistances[neighbour.ix] = candidate;
                    pool.add(new Pair(candidate, neighbour));
                    nodesInPool++;
                } else if (candidate < nodeDistances[neighbour.ix]) {
                    nodeDistances[neighbour.ix] = candidate;
                    pool.add(new Pair(candidate, neighbour));
                }

                neighbour.neighbours.remove(node);

            }
        }

        return nodeDistances;
    }

}

class Pair implements Comparable<Pair> {

    final long weight;

    final Node node;

    public Pair(long weight, Node node) {
        super();
        this.weight = weight;
        this.node = node;
    }

    @Override
    public int compareTo(Pair o) {
        return Long.compare(weight, o.weight);
    }

}

class Graph {
    final Node[] nodes;
    // final Set<Edge> edges;

    public Graph(short nodes) {
        this.nodes = new Node[nodes];
        // this.edges = new HashSet<>(edges);
    }

    public void createEdge(short x, short y, int r) {
        final Node X = this.getNode(x);
        final Node Y = this.getNode(y);
        final Integer existingEdge = X.neighbours.get(Y);
        if ((existingEdge == null) || (r < existingEdge)) {
            X.neighbours.put(Y, r);
            Y.neighbours.put(X, r);
        }

        // edges.add(edge);
    }

    public Node getNode(short ix) {
        if (nodes[ix] == null) {
            nodes[ix] = new Node(ix);
        }
        return nodes[ix];
    }

}

class Node {

    final short ix;

    final Map<Node, Integer> neighbours = new HashMap<>();

    public Node(short ix) {
        this.ix = ix;
    }

    @Override
    public int hashCode() {

        return ix;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Node other = (Node) obj;
        if (ix != other.ix)
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Node [ix=" + ix + "]";
    }

}


