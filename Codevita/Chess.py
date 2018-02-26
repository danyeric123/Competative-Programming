from math import atan2
from copy import deepcopy
from collections import namedtuple

DIRECTIONS = [(1, 0), (1, 1), (0, 1), (-1, 1),
              (-1, 0), (-1, -1), (0, -1), (1, -1),
              (2, 1), (1, 2), (-1, 2), (-2, 1),
              (-2, -1), (-1, -2), (1, -2), (2, -1),
              ]
RAYS = [atan2(d[1], d[0]) for d in DIRECTIONS]
SQUARE = dict()
cnt = 0
for i in range(8):
    for j in range(8):
        SQUARE[(chr(ord("a")+j)+str(8-i))]  = cnt
        cnt += 1

PIECES = {'k': lambda y, dx, dy: abs(dx) <= 1 and abs(dy) <= 1,
          'q': lambda y, dx, dy: dx == 0 or dy == 0 or abs(dx) == abs(dy),
          'n': lambda y, dx, dy: (abs(dx) >= 1 and
                                  abs(dy) >= 1 and
                                  abs(dx) + abs(dy) == 3),
          'b': lambda y, dx, dy: abs(dx) == abs(dy),
          'r': lambda y, dx, dy: dx == 0 or dy == 0,
          'p': lambda y, dx, dy: (y < 8 and abs(dx) <= 1 and dy == -1),
          'P': lambda y, dx, dy: (y > 1 and abs(dx) <= 1 and dy == 1),
          }

MOVES = dict()

for sym, is_legal in PIECES.items():
    MOVES[sym] = list()
    for idx in range(64):
        MOVES[sym].append([list() for _ in range(8)])
        for end in sorted(range(64), key=lambda x: abs(x - idx)):
            y = 8 - idx // 8
            dx = (end % 8) - (idx % 8)
            dy = (8 - end // 8) - y

            if idx == end or not is_legal(y, dx, dy):
                continue

            angle = atan2(dy, dx)
            if angle in RAYS:
                ray_num = RAYS.index(angle) % 8
                MOVES[sym][idx][ray_num].append(end)
        MOVES[sym][idx] = [r for r in MOVES[sym][idx] if r]

for sym in ['K', 'Q', 'N', 'B', 'R']:
    MOVES[sym] = deepcopy(MOVES[sym.lower()])

MOVES['k'][4][0].append(6)
MOVES['k'][4][1].append(2)
MOVES['K'][60][0].append(62)
MOVES['K'][60][4].append(58)
IDX = 0
for i in range(8):
    MOVES['p'][8 + i][IDX].append(24 + i)
    MOVES['P'][55 - i][IDX].append(39 - i)
    IDX = 1


class Board(object):
    def __init__(self, position=' ' * 64):
        self._position = []
        self.set_position(position)
    def __str__(self):
        pos = []
        for idx, piece in enumerate(self._position):
            if idx > 0 and idx % 8 == 0:
                pos.append('/')
            if not piece.isspace():
                pos.append(piece)
            elif pos and pos[-1].isdigit():
                pos[-1] = str(int(pos[-1]) + 1)
            else:
                pos.append('1')
        return ''.join(pos)

    def set_position(self, position):
        self._position = []
        for char in position:
            if char == '/':
                continue
            elif char.isdigit():
                self._position.extend([' '] * int(char))
            else:
                self._position.append(char)

    def get_piece(self, index):
        return self._position[index]

    def get_owner(self, index):
        piece = self.get_piece(index)
        if not piece.isspace():
            return 'w' if piece.isupper() else 'b'
        return None

    def move_piece(self, start, end, piece):
        self._position[end] = piece
        self._position[start] = ' '

    def find_piece(self, symbol):
        return ''.join(self._position).find(symbol)

State = namedtuple('State', ['player', 'rights', 'en_passant', 'ply', 'turn'])


class InvalidMove(Exception):
    pass

class Game(object):
    NORMAL = 0
    CHECK = 1
    CHECKMATE = 2
    STALEMATE = 3

    default_fen = 'rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1'
    def __init__(self, fen=default_fen, validate=True):
        self.board = Board()
        self.state = State(' ', ' ', ' ', ' ', ' ')
        self.move_history = []
        self.fen_history = []
        self.validate = validate
        self.set_fen(fen=fen)

    def __str__(self):
        return ' '.join(str(x) for x in [self.board] + list(self.state))

    @staticmethod
    def i2xy(pos_idx):
        return chr(97 + pos_idx % 8) + str(8 - pos_idx // 8)

    @staticmethod
    def xy2i(pos_xy):
        return (8 - int(pos_xy[1])) * 8 + (ord(pos_xy[0]) - ord('a'))

    def get_fen(self):
        return ' '.join(str(x) for x in [self.board] + list(self.state))

    def set_fen(self, fen):
        self.fen_history.append(fen)
        fields = fen.split(' ')
        fields[4] = int(fields[4])
        fields[5] = int(fields[5])
        self.state = State(*fields[1:])
        self.board.set_position(fields[0])

    def reset(self, fen=default_fen):
        self.move_history = []
        self.fen_history = []
        self.set_fen(fen)

    def apply_move(self, move):
        fields = ['w', 'KQkq', '-', 0, 1]
        if move is None or move == '' or len(move) < 4:
            raise InvalidMove("\nIllegal move: {}\nfen: {}".format(move,
                                                                   str(self)))
        move = move.lower()

        start = Game.xy2i(move[:2])
        end = Game.xy2i(move[2:4])
        piece = self.board.get_piece(start)
        target = self.board.get_piece(end)

        if self.validate and move not in self.get_moves(idx_list=[start]):
            raise InvalidMove("\nIllegal move: {}\nfen: {}".format(move,
                                                                   str(self)))
        fields[0] = {'w': 'b', 'b': 'w'}[self.state.player]
        rights_map = {0: 'q', 4: 'kq', 7: 'k',
                      56: 'Q', 60: 'KQ', 63: 'K'}
        void_set = ''.join([rights_map.get(start, ''),
                           rights_map.get(end, '')])
        new_rights = [r for r in self.state.rights if r not in void_set]
        fields[1] = ''.join(new_rights) or '-'
        if piece.lower() == 'p' and abs(start - end) == 16:
            fields[2] = Game.i2xy((start + end) // 2)
        fields[3] = self.state.ply + 1
        if piece.lower() == 'p' or target.lower() != ' ':
            fields[3] = 0

        fields[4] = self.state.turn
        if self.state.player == 'b':
            fields[4] = self.state.turn + 1
        if len(move) == 5:
            piece = move[4]
            if self.state.player == 'w':
                piece = piece.upper()
        self.move_history.append(move)
        self.board.move_piece(start, end, piece)
        c_type = {62: 'K', 58: 'Q', 6: 'k', 2: 'q'}.get(end, None)
        if piece.lower() == 'k' and c_type and c_type in self.state.rights:
            coords = {'K': (63, 61), 'Q': (56, 59),
                      'k': (7, 5), 'q': (0, 3)}[c_type]
            r_piece = self.board.get_piece(coords[0])
            self.board.move_piece(coords[0], coords[1], r_piece)
        if piece.lower() == 'p' and self.state.en_passant != '-' \
                and Game.xy2i(self.state.en_passant) == end:
            ep_tgt = Game.xy2i(self.state.en_passant)
            if ep_tgt < 24:
                self.board.move_piece(end + 8, end + 8, ' ')
            elif ep_tgt > 32:
                self.board.move_piece(end - 8, end - 8, ' ')
        self.set_fen(' '.join(str(x) for x in [self.board] + list(fields)))

    def get_moves(self, player=None, idx_list=range(64)):
        if not self.validate:
            return self._all_moves(player=player, idx_list=idx_list)

        if not player:
            player = self.state.player

        res_moves = []
        test_board = Game(fen=str(self), validate=False)
        for move in self._all_moves(player=player, idx_list=idx_list):

            test_board.reset(fen=str(self))
            k_sym, opp = {'w': ('K', 'b'), 'b': ('k', 'w')}.get(player)
            kdx = self.board.find_piece(k_sym)
            k_loc = Game.i2xy(kdx)
            dx = abs(kdx - Game.xy2i(move[2:4]))

            if move[0:2] == k_loc and dx == 2:

                op_moves = set([m[2:4] for m in test_board.get_moves(player=opp)])
                castle_gap = {'e1g1': 'e1f1', 'e1c1': 'e1d1',
                              'e8g8': 'e8f8', 'e8c8': 'e8d8'}.get(move, '')
                if (k_loc in op_moves or castle_gap and castle_gap not in res_moves):
                    continue

            test_board.apply_move(move)
            tgts = set([m[2:4] for m in test_board.get_moves()])
            if Game.i2xy(test_board.board.find_piece(k_sym)) not in tgts:
                res_moves.append(move)
        return res_moves

    def _all_moves(self, player=None, idx_list=range(64)):
        player = player or self.state.player
        res_moves = []
        for start in idx_list:
            if self.board.get_owner(start) != player:
                continue
            piece = self.board.get_piece(start)
            rays = MOVES.get(piece, [''] * 64)

            for ray in rays[start]:
                new_moves = self._trace_ray(start, piece, ray, player)
                res_moves.extend(new_moves)
        return res_moves

    def _trace_ray(self, start, piece, ray, player):
        res_moves = []
        for end in ray:
            sym = piece.lower()
            del_x = abs(end - start) % 8
            move = [Game.i2xy(start) + Game.i2xy(end)]
            tgt_owner = self.board.get_owner(end)
            if tgt_owner == player:
                break
            if sym == 'k' and del_x == 2:
                gap_owner = self.board.get_owner((start + end) // 2)
                out_owner = self.board.get_owner(end - 1)
                rights = {62: 'K', 58: 'Q', 6: 'k', 2: 'q'}.get(end, ' ')
                if (tgt_owner or gap_owner or rights not in self.state.rights or
                        (rights.lower() == 'q' and out_owner)):
                    break

            if sym == 'p':
                if del_x == 0 and tgt_owner:
                    break
                elif del_x != 0 and not tgt_owner:
                    ep_coords = self.state.en_passant
                    if ep_coords == '-' or end != Game.xy2i(ep_coords):
                        break
                if (end < 8 or end > 55):
                    move = [move[0] + s for s in ['b', 'n', 'r', 'q']]

            res_moves.extend(move)
            if tgt_owner:
                break

        return res_moves

    @property
    def status(self):

        k_sym, opp = {'w': ('K', 'b'), 'b': ('k', 'w')}.get(self.state.player)
        k_loc = Game.i2xy(self.board.find_piece(k_sym))
        can_move = len(self.get_moves())
        is_exposed = [m[2:] for m in self._all_moves(player=opp)
                      if m[2:] == k_loc]
        status = Game.NORMAL
        if is_exposed:
            status = Game.CHECK
            if not can_move:
                status = Game.CHECKMATE
        elif not can_move:
            status = Game.STALEMATE
        return status

def fen_board(fen):
    board = []
    row = ""
    for ch in fen:
        if ch >= '1' and ch <='8':
            row += ". "*int(ch)
        elif ch == "/":
            board.append(row)
            row = ""
        else:
            row += ch+" "
    board.append(row)
    for i in range(8):
        print(board[i])

def find_move(before_fen,after_fen):
    before = Game(before_fen)
    after = Game(after_fen)
    moves = before.get_moves()
    for move in moves:
        before = Game(before_fen)
        before.apply_move(move)
        if str(before)[0] == str(after)[0]:
            return move

    raise Exception("Move Not Found")


game = Game("r1b2rk1/1p4pR/p2pppn1/6q1/3NP1P1/2N2P2/PPP4Q/1K5R w - - 0 0")
print(str(game))
fen_board(str(game).split()[0])
for move1 in game.get_moves():
    board1 = Game("r1b2rk1/1p4pR/p2pppn1/6q1/3NP1P1/2N2P2/PPP4Q/1K5R w - - 0 0")
    board1.apply_move(move1)
    if board1.status != Game.CHECK :
        continue
    for move2 in board1.get_moves():
        board2 = Game(str(board1))
        board2.apply_move(move2)
        for move3 in board2.get_moves():
            board3 = Game(str(board2))
            board3.apply_move(move3)
            if board3.status == Game.CHECKMATE:
                print (move1+"-"+move2+"-"+move3)
