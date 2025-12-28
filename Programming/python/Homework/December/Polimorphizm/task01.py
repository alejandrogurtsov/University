from abc import ABC, abstractmethod

class ChessPiece(ABC):
    def __init__(self, horizontal, vertical):
        self.horizontal = horizontal
        self.vertical = vertical

    @abstractmethod
    def can_move(self):
        pass

class King(ChessPiece):
    def __init__(self, horizontal, vertical):
        super().__init__(horizontal, vertical)

    def can_move(self, horizontal, vertical):
        dx = abs(ord(horizontal) - ord(self.horizontal))
        dy = abs(vertical - self.vertical)
        return dx <= 1 and dy <= 1 and (dx != 0 or dy != 0)

class Knight(ChessPiece):
    def __init__(self, horizontal, vertical):
        super().__init__(horizontal, vertical)

    def can_move(self, horizontal, vertical):
        dx = abs(ord(horizontal) - ord(self.horizontal))
        dy = abs(vertical - self.vertical)
        return (dx == 2 and dy == 1) or (dx == 1 and dy == 2)

pieces = [
    King('e', 1),
    Knight('b', 1)
]

test_moves = [('c', 3), ('e', 2), ('f', 1), ('a', 3), ('d', 3)]

for piece in pieces:
    print(f"\nТестируем {piece.__class__.__name__} на позиции {piece.horizontal}{piece.vertical}:")
    for move in test_moves:
        can_move = piece.can_move(move[0], move[1])
        print(f"Может ли пойти на {move[0]}{move[1]}? => {can_move}")