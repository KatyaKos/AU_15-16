__author__ = 'KatyaKos'
from model import *
import copy
class IatVisitor:
    pass

class ConstantFolder(IatVisitor):

    def visit(self, char):
         name = char.__class__.__name__
         char1 = copy.deepcopy(char)
         try:
             fn = getattr(self, 'visit' + name)
         except AttributeError:
             print("Method for {} not found!".format(name))
             raise NotImplementedError
         return fn(char1)

    def visitSentence(self, sentences):
        list = []
        for el in sentences:
            list.append(el.visit(self))
        return list

    def visitNumber(self, number):
        return number

    def visitReference(self, reference):
        return reference

    def visitConditional(self, conditional):
        conditional.condition = conditional.condition.visit(self)
        conditional.if_true = self.visitSentence(conditional.if_true)
        if (conditional.if_false != None):
            conditional.if_false = self.visitSentence(conditional.if_false)
        return conditional

    def visitFunctionDefinition(self, functiondefinition):
        functiondefinition.function.body = self.visitSentence(functiondefinition.function.body)
        return functiondefinition

    def visitPrint(self, printi):
        printi.expr = printi.expr.visit(self)
        return printi

    def visitRead(self, readi):
        return readi

    def visitBinaryOperation(self, binop):
        if (isinstance(binop.lhs, Number) and isinstance(binop.rhs, Number) and binop.op == '*'):
            return binop.evaluate(self)
        elif (isinstance(binop.lhs, Number) and binop.lhs.value == 0 and isinstance(binop.rhs, Reference) and binop.op == '*'):
            return Number(0)
        elif (isinstance(binop.rhs, Number) and binop.rhs.value == 0 and isinstance(binop.lhs, Reference) and binop.op == '*'):
            return Number(0)
        elif (isinstance(binop.rhs, Reference) and isinstance(binop.lhs, Reference) and binop.op == '-'):
            return binop.evaluate(self)
        else:
            binop.lhs = binop.lhs.visit(self)
            binop.rhs = binop.rhs.visit(self)
            return binop

    def visitUnaryOperation(self, unop):
        return unop.evaluate(self)

    def visitFunctionCall(self, funcall):
        funcall.fun_expr = funcall.fun_expr.visit(self)
        return funcall

