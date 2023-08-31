import copy


class State:
    def __init__(self, grid) -> None:
        self.grid = grid

    def __str__(self) -> str:
        result = ""
        for row in self.grid:
            for value in row:
                result += f"{value}  "
            result += "\n"
        return result

    def get_blank(self):
        for r, row in enumerate(self.grid):
            for c, value in enumerate(row):
                if value not in [1, 2, 3, 4, 5, 6, 7, 8]:
                    return r, c

    def move(self, direction=None):
        blank_tile = self.get_blank()

        match direction:
            case "right":
                target_tile = blank_tile[0], blank_tile[1] + 1
            case "left":
                target_tile = blank_tile[0], blank_tile[1] - 1
            case "up":
                target_tile = blank_tile[0] - 1, blank_tile[1]
            case "down":
                target_tile = blank_tile[0] + 1, blank_tile[1]
            case _:
                raise ValueError("Invalid Direction")

        for index in target_tile:
            if not (0 <= index <= 2):
                return None

        new_state = State(self.grid[:])
        new_state.grid[blank_tile[0]][blank_tile[1]
                                      ] = new_state.grid[target_tile[0]][target_tile[1]]
        new_state.grid[target_tile[0]][target_tile[1]] = 0

        return new_state


def solve(current: State, final_state, tracks=[]):
    if not current:
        print("[x] impossible move")
        return None

    # If goal, return
    if current.grid == final_state.grid:
        print(f"[v] found goal!")
        return tracks + [current.grid]

    print(f"{current.grid=}")

    # If duplicate, ignore move
    # for t_grid in tracks:
    if current.grid in tracks:
        print(f"[-] already taken, ignore")
        return None

    # Move in all directions
    fn_tracks = tracks + [current.grid]
    fn_tracks = copy.deepcopy(fn_tracks)
    for direction in ["right", "up", "left", "down"]:
        print(f"> Moving {direction}.")
        if result := solve(current=current.move(direction=direction),
                           final_state=final_state,
                           tracks=fn_tracks):
            return result
    else:
        return None


def main():
    current = State([
        [1, 2, 3],
        [7, 8, 4],
        [0, 6, 5],
    ])

    final_state = State([
        [1, 8, 2],
        [7, 5, 3],
        [6, 0, 4],
    ])

    for state in solve(current=current, final_state=final_state):
        print(State(state))


main()
