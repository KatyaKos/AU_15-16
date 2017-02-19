#!/usr/bin/env python3

class Iat:
    pass

class Scope(Iat):

    def __init__(self, parent=None):
        self.value = {}
        self.parent = parent

    def __getitem__(self, key):
        if key in self.value:
            return self.value[key]
        else:
            return self.parent[key]

    def __setitem__(self, key, x):
        self.value[key] = x


class Number(Iat):

    def __init__(self, value):
        self.value = int(value)

    def visit(self, visitor):
        return visitor.visitNumber(self)

    def evaluate(self, scope):
        return self


class Function(Iat):

    def __init__(self, args, body):
        self.args = args
        self.body = body

    def evaluate(self, scope):
        result = None

        for op in self.body:
            result = op.evaluate(scope)
        return result

class FunctionDefinition(Iat):

    def __init__(self, name, function):
        self.name = name
        self.function = function

    def evaluate(self, scope):
        scope[self.name] = self.function
        return self.function
    def visit(self, visitor):
        return visitor.visitFunctionDefinition(self)

class Conditional(Iat):

    def __init__(self, condition, if_true, if_false=None):
        self.condition = condition
        self.if_true = if_true
        self.if_false = if_false

    def evaluate(self, scope):
        if self.condition.evaluate(scope).value == 0:
            list = self.if_false
        else:
            list = self.if_true

        result = None
        for el in list:
            result = el.evaluate(scope)
        return result

    def visit(self, visitor):
        return visitor.visitConditional(self)

class Print(Iat):

    def __init__(self, expr):
        self.expr = expr

    def evaluate(self, scope):
        result = self.expr.evaluate(scope).value
        print(result)
        return self.expr

    def visit(self, visitor):
        return visitor.visitPrint(self)

class Read(Iat):

    def __init__(self, name):
        self.name = name

    def evaluate(self, scope):
        value = Number(input())
        scope[self.name] = value
        return value

    def visit(self, visitor):
        return visitor.visitRead(self)

class FunctionCall(Iat):

    def __init__(self, fun_expr, args):
        self.fun_expr = fun_expr
        self.args = args

    def evaluate(self, scope):
        function = self.fun_expr.evaluate(scope)
        arguments = [arg.evaluate(scope) for arg in self.args]
        call_scope = Scope(scope)
        i = 0
        for name, value in zip(function.args, arguments):
            call_scope[name] = value
            i += 1
        return function.evaluate(call_scope)

    def visit(self, visitor):
        return visitor.visitFunctionCall(self)

class Reference(Iat):

    def __init__(self, name):
        self.name = name

    def evaluate(self, scope):
        return scope[self.name]

    def visit(self, visitor):
        return visitor.visitReference(self)

class BinaryOperation(Iat):

    def __init__(self, lhs, op, rhs):
        self.lhs = lhs
        self.op = op
        self.rhs = rhs

    def evaluate(self, scope):
        lhs = self.lhs.evaluate(scope).value
        rhs = self.rhs.evaluate(scope).value

        operations = {
            "+": lambda l, r: l + r,
            "-": lambda l, r: l - r,
            "*": lambda l, r: l * r,
            "/": lambda l, r: l / r,
            "%": lambda l, r: l % r,
            "<": lambda l, r: l < r,
            ">": lambda l, r: l > r,
            "==": lambda l, r: l == r,
            "!=": lambda l, r: l != r,
            "<=": lambda l, r: l <= r,
            ">=": lambda l, r: l >= r,
            "&&": lambda l, r: l and r,
            "||": lambda l, r: l or r
        }

        op = operations[self.op]
        return Number(op(lhs, rhs))

    def visit(self, visitor):
        return visitor.visitBinaryOperation(self)

class UnaryOperation(Iat):

    def __init__(self, op, expr):
        self.op = op
        self.expr = expr

    def evaluate(self, scope):
        expr = self.expr.evaluate(scope)
        if self.op == '-':
            return Number(-1 * expr.value)
        else:
            return Number(expr.value != 0)

    def visit(self, visitor):
        return visitor.visitUnaryOperation(self)

"""def example():
    parent = Scope()
    parent["foo"] = Function(('hello', 'world'),
                             [Print(BinaryOperation(Reference('hello'),
                                                    '+',
                                                    Reference('world')))])
    parent["bar"] = Number(10)
    scope = Scope(parent)
    assert 10 == scope["bar"].value
    scope["bar"] = Number(20)
    assert scope["bar"].value == 20
    print('Print two:', end=' ')
    FunctionCall(FunctionDefinition('foo', parent['foo']),
                 [Number(5), UnaryOperation('-', Number(3))]).evaluate(scope)

def my_tests():
    parent = Scope()
    Read("a").evaluate(parent)
    Read("b").evaluate(parent)
    Print(BinaryOperation(Reference("a"), "||", Reference("b"))).evaluate(parent)
    Conditional(UnaryOperation('!', Reference('a')), [Print(Number(1))], [Print(Number(0))]).evaluate(parent)
    scope = Scope(parent)
    scope["mod"] = Function(('c', 'd'),
                             [Print(BinaryOperation(Reference('c'),
                                                    '%',
                                                    Reference('d')))])
    FunctionCall(FunctionDefinition('mod', scope['mod']),
                 [Number(6), Number(4)]).evaluate(scope)

if __name__ == '__main__':
    example()
    my_tests()"""