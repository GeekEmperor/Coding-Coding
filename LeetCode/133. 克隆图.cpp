class Solution {
public:
    vector<Node*> visited{101, nullptr};
    Node* cloneGraph(Node* node) {
        if(visited[node->val])
            return visited[node->val];
        Node* copy = new Node(node->val, node->neighbors);
        visited[copy->val] = copy;
        for(int i = 0; i < copy->neighbors.size(); ++i)
            copy->neighbors[i] = cloneGraph(copy->neighbors[i]);
        return copy;
    }
};