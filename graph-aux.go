package main

type Vertex struct {
	Key      int
	Vertices map[int]*Vertex
}

func NewVertex(key int) *Vertex {
	return &Vertex{
		Key:      key,
		Vertices: map[int]*Vertex{},
	}
}

type Graph struct {
	Vertices map[int]*Vertex
	directed bool
}

func NewUndirectedGraph() *Graph {
	return &Graph{
		Vertices: map[int]*Vertex{},
	}
}

func (g *Graph) AddVertex(key int) {
	v := NewVertex(key)
	g.Vertices[key] = v
	/* fmt.Print("vertice: ")
	fmt.Println(g.Vertices[key].Key) */
}

func (g *Graph) AddEdge(k1, k2 int) {
	v1 := g.Vertices[k1]
	v2 := g.Vertices[k2]

	if v1 == nil || v2 == nil {
		panic("Nem todos os vertices existem")
	}

	if _, ok := v1.Vertices[v2.Key]; ok {
		return
	}

	v1.Vertices[v2.Key] = v2
	if !g.directed && v1.Key != v2.Key {
		v2.Vertices[v1.Key] = v1
	}

	g.Vertices[v1.Key] = v1
	g.Vertices[v2.Key] = v2
	/* fmt.Print("edges: ")
	fmt.Println(g.Vertices[v1.Key].Key)
	fmt.Println(g.Vertices[v2.Key].Key) */
}
