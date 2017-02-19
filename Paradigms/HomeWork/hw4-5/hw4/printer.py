__author__ = 'KatyaKos'
from model import *
from folder import *
class IatVisitor:
    pass

class PrettyPrinter(IatVisitor):

    def __init__(self):
        self.space = 0

    def printSpace(self, space):
        for i in range(space):
            print(end = '    ')

    def visit(self, char):
         name = char.__class__.__name__
         self.space = 0
         try:
             fn = getattr(self, 'visit' + name)
         except AttributeError:
             print("Method for {} not found!".format(name))
             raise NotImplementedError
         #print(";")
         fn(char)
         print(";")

    def visitSentence(self, sentences):
        self.space += 1
        for el in sentences:
            el.visit(self)
            print(";")
        self.space -= 1

    def visitNumber(self, number):
        self.printSpace(self.space)
        print(number.value, end = '')

    def visitReference(self, reference):
        self.printSpace(self.space)
        print(reference.name, end = '')

    def visitConditional(self, conditional):
        self.printSpace(self.space)
        print("if (", end = '')
        conditional.condition.visit(self)
        print(") {")
        self.visitSentence(conditional.if_true)
        self.printSpace(self.space)
        print("} else {")
        if (conditional.if_false != None):
            self.visitSentence(conditional.if_false)
        self.printSpace(self.space)
        print("}", end = '')

    def visitFunctionDefinition(self, functiondefinition):
        self.printSpace(self.space)
        print("def ", functiondefinition.name, sep = '', end = "(")
        n = len(functiondefinition.function.args)
        for i in range(n - 1):
            print(functiondefinition.function.args[i], end = ", ")
        if (n != 0):
            print(functiondefinition.function.args[n - 1], end = ") {\n")
        else:
            print(") {")
        self.visitSentence(functiondefinition.function.body)
        self.printSpace(self.space)
        print("}", end = '')

    def visitPrint(self, printi):
        self.printSpace(self.space)
        print("print ", end = '')
        tmp = self.space
        self.space = 0
        printi.expr.visit(self)
        self.space = tmp
        print("", end = '')

    def visitRead(self, readi):
        self.printSpace(self.space)
        print("read", readi.name, end = '')
        print("", end = '')

    def visitBinaryOperation(self, binop):
        self.printSpace(self.space)
        print('(', end = '')
        tmp = self.space
        self.space = 0
        binop.lhs.visit(self)
        print(')', binop.op, '(', end = '')
        binop.rhs.visit(self)
        self.space = tmp
        print(")", end = '')

    def visitUnaryOperation(self, unop):
        self.printSpace(self.space)
        print(unop.op, end = '')
        tmp = self.space
        self.space = 0
        unop.expr.visit(self)
        self.space = tmp

    def visitFunctionCall(self, funcall):
        funcall.fun_expr.visit(self)
        tmp = self.space
        self.space = 0
        print("(", end = '')
        n = len(funcall.args)
        for i in range(n - 1):
            funcall.args[i].visit(self)
            print(", ", end = '')
        if (n != 0):
            funcall.args[n - 1].visit(self)
        print(")", end = '')
        self.space = tmp


def example():
    folder = ConstantFolder()
    n0, n1, n2 = Number(1), Number(2), Number(3)
    add = BinaryOperation(n1, '*', n2)
    mul = BinaryOperation(n0, '+', add)
    mul1 = folder.visit(mul)
    printer = PrettyPrinter()
    printer.visit(mul1)


    """num = Number(42)
    cond = Conditional(num, [Number(1)], [])
    printer = PrettyPrinter()
    printer.visit(num)
    printer.visit(cond)

    func = Function([], [])
    defin = FunctionDefinition("foo", func)
    printer.visit(defin)

    print = Print(num)
    printer.visit(print)
    read = Read("x")
    printer.visit(read)

    reference = Reference("a")
    printer.visit(reference)

    printer.visit(mul)

    unary = UnaryOperation('-', num)
    printer.visit(unary)

    reference = Reference("foo")
    call = FunctionCall(reference, [Number(1), Number(2), Number(3)])
    printer.visit(call)

    tr = Function(('hello', 'world'),
                             [Print(BinaryOperation(Reference('hello'),
                                                    '+',
                                                    Reference('world')))])

    tri = FunctionCall(FunctionDefinition('foo', tr),
                 [Number(5), UnaryOperation('-', Number(3))])
    printer.visit(tri)"""

if __name__ == '__main__':
    example()




