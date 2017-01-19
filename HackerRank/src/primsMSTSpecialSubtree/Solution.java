package primsMSTSpecialSubtree;

import java.io.BufferedInputStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(new BufferedInputStream(System.in));

		short N = sc.nextShort();
		int M = sc.nextInt();
		final Graph graph = new Graph((short) (N + 1), M);
		for (int i = 0; i < M; i++) {
			short x = sc.nextShort();
			short y = sc.nextShort();
			int r = sc.nextInt();
			graph.createEdge(x, y, r);
		}
		short startIX = sc.nextShort();
		long result = process(graph, startIX);
		System.out.println(result);
		sc.close();
	}

	private static long process(Graph graph, short startIX) {
		final Node startNode = graph.nodes[startIX];
		startNode.marked = true;
		int notMarkedNodes = graph.nodes.length - 2;

		final PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.addAll(startNode.edges.values());

		long sum = 0;
		while (!pq.isEmpty()) {
			final Edge currEdge = pq.poll();
			sum += currEdge.weight;
			final Node node = currEdge.end;
			node.marked = true;
			notMarkedNodes--;
			if (notMarkedNodes <= 0)
				break;

			final Iterator<Edge> iterator = pq.iterator();
			while (iterator.hasNext())
				if (iterator.next().end.marked)
					iterator.remove();

			for (Edge edge : node.edges.values())
				if (!edge.end.marked)
					pq.add(edge);

		}

		return sum;
	}
}

class Graph {
	final Node[] nodes;
	// final Set<Edge> edges;

	public Graph(short nodes, int edges) {
		this.nodes = new Node[nodes];
		// this.edges = new HashSet<>(edges);
	}

	public void createEdge(short x, short y, int r) {
		final Node X = this.getNode(x);
		final Node Y = this.getNode(y);
		final Edge newEdge = new Edge(r, X, Y);
		final Edge existingEdge = X.edges.get(Y);
		if ((existingEdge == null) || (newEdge.compareTo(existingEdge) < 0)) {
			X.edges.put(Y, newEdge);
			Y.edges.put(X, new Edge(r, Y, X));
		}

		// edges.add(edge);
	}

	private Node getNode(short ix) {
		Node node = nodes[ix];
		if (node == null) {
			node = new Node(ix);
			nodes[ix] = node;
		}
		return node;
	}

}

class Node {

	final short ix;
	boolean marked = false;
	final Map<Node, Edge> edges = new HashMap<>();

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

}

class Edge implements Comparable<Edge> {
	final int weight;
	final Node start;
	final Node end;

	public Edge(int r, Node start, Node end) {

		this.weight = r;
		this.start = start;
		// n1.edges.add(this);
		this.end = end;
		// n2.edges.add(this);
	}



	@Override
	public int compareTo(Edge o) {
		int res = Integer.compare(weight, o.weight);
		if (res == 0) {
			int candidate1 = weight + start.ix + end.ix;
			int candidate2 = o.weight + o.start.ix + o.end.ix;
			res = Integer.compare(candidate1, candidate2);
		}
		return res;
	}
}
