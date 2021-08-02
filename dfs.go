package main

func DFS(g *Graph, startVertex *Vertex, visitCb func(int)) {
	visited := map[int]bool{}

	/* fmt.Println("come;o") */

	if startVertex == nil {
		return
	}
	visited[startVertex.Key] = true
	visitCb(startVertex.Key)

	for _, v := range startVertex.Vertices {
		/* fmt.Println("entrei") */
		//fmt.Println(visited[v.Key])
		if visited[v.Key] {
			//fmt.Println("visitado")
			continue
		}
		DFS(g, v, visitCb)
	}
}
