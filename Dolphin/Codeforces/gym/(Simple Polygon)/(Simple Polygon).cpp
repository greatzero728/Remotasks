#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Point {
    double x, y;
};

struct Edge {
    Point start, end;
};

bool isLeft(const Point& p, const Edge& e) {
    double crossProduct = (e.end.x - e.start.x) * (p.y - e.start.y) -
                          (e.end.y - e.start.y) * (p.x - e.start.x);
    return crossProduct > 0;
}

Point getIntersection(const Edge& e1, const Edge& e2) {
    double x1 = e1.start.x;
    double y1 = e1.start.y;
    double x2 = e1.end.x;
    double y2 = e1.end.y;

    double x3 = e2.start.x;
    double y3 = e2.start.y;
    double x4 = e2.end.x;
    double y4 = e2.end.y;

    double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) /
               ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

    double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) /
               ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

    return {x, y};
}

bool isIntersecting(const std::vector<Edge>& edges) {
    struct Event {
        double x;
        int index;
        char type;
        bool operator<(const Event& other) const {
            return x < other.x;
        }
    };

    std::vector<Event> events;
    std::set<int> sweepLine;
    std::vector<Edge> activeEdges;

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].start.x == edges[i].end.x)
            continue;

        Event e;
        e.x = std::min(edges[i].start.x, edges[i].end.x);
        e.index = i;
        e.type = 'l';
        events.push_back(e);

        e.x = std::max(edges[i].start.x, edges[i].end.x);
        e.type = 'r';
        events.push_back(e);
    }

    std::sort(events.begin(), events.end());
    for (int i = 0; i < events.size(); i++) {
        auto e = events[i];
        if (e.type == 'l') {
            for (auto activeEdge : activeEdges) {
                Point intersection = getIntersection(edges[e.index], activeEdge);
                if (isLeft(intersection, activeEdge) && isLeft(intersection, edges[e.index])) {
                    return true;  // Intersection found
                }
            }
            activeEdges.push_back(edges[e.index]);
            sweepLine.insert(edges[e.index].start.y);
        } else {
            activeEdges.erase(std::remove(activeEdges.begin(), activeEdges.end(), edges[e.index]), activeEdges.end());
            sweepLine.erase(edges[e.index].start.y);
        }
        auto it = sweepLine.upper_bound(edges[e.index].start.y);
        if (it != sweepLine.end()) {
            for (auto activeEdge : activeEdges) {
                Point intersection = getIntersection(edges[e.index], activeEdge);
                if (isLeft(intersection, activeEdge) && isLeft(intersection, edges[e.index])) {
                    return true;  // Intersection found
                }
            }
        }
    }
    return false;
}

bool isSimplePolygon(const std::vector<Point>& vertices) {
    std::vector<Edge> edges;
    for (int i = 0; i < vertices.size() - 1; i++) {
        edges.push_back({vertices[i], vertices[i + 1]});
    }
    edges.push_back({vertices[vertices.size() - 1], vertices[0]});

    bool isIntersecting1 = isIntersecting(edges);
    if (isIntersecting1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    std::vector<Point> vertices = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};  // Example polygon
    bool isSimple = isSimplePolygon(vertices);
    if (isSimple) {
        
    }
}
