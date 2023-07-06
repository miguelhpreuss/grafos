class FamilyTree:
    def __init__(self, parents, came_list):
        self.n = len(parents)
        self.children = [[] for _ in range(self.n + 1)]
        for child_id, parent_id in enumerate(parents, 1):
            self.children[parent_id].append(child_id)

        self.came = [False] * (self.n + 1)
        for id in came_list:
            self.came[id] = True

        self.gen_many = [0] * (self.n + 1)
        self.gen_came = [0] * (self.n + 1)

    def calculate_percentages(self):
        self.dfs(0, 0)

        percentages = []
        for d in range(1, self.n + 1):
            if self.gen_many[d] == 0:
                break
            percentage = 100.0 * self.gen_came[d] / self.gen_many[d]
            percentages.append("{:.2f}".format(percentage))

        return percentages

    def dfs(self, v, dist):
        self.gen_many[dist] += 1
        if self.came[v]:
            self.gen_came[dist] += 1

        for son in self.children[v]:
            self.dfs(son, dist + 1)


def main():
    n, m = map(int, input().split())
    parents = list(map(int, input().split()))
    came_list = list(map(int, input().split()))

    family_tree = FamilyTree(parents, came_list)
    percentages = family_tree.calculate_percentages()

    print(" ".join(percentages))


if __name__ == '__main__':
    main()
