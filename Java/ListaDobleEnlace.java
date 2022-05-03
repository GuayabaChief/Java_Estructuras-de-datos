public class ListaDobleEnlace<T>{
        /**
           * Clase de nodo, privada. Almacene el valor del nodo
           * Y la direcci�n del nodo anterior y del siguiente nodo
     */
    private class Node {
        T element;
        Node previous; // apunta al nodo anterior del nodo
        Node next; // apunta al siguiente nodo del nodo

        Node() {
        }

        // estructura
        Node(T element) {
            this.element = element;
        }
    }

    // registra el primer nodo
    private Node first;
    // registra el �ltimo nodo
    private Node last;
    // Registra el n�mero de nodos en la lista vinculada
    private int count;


    /**
           * Obtenga el n�mero de nodos en la lista vinculada
     *
           * @return el n�mero de nodos
     */
    public int size() {
        return count;
    }

    /**
           * Obtenga el nodo correspondiente seg�n el sub�ndice y regrese
     *
           * @param index necesita obtener el sub�ndice del nodo
           * @return el nodo correspondiente al sub�ndice
     */
    private Node getNode(int index) {
        // Obtener el valor del elemento seg�n el �ndice
        if (index < 0 || index >= count) {
            // Si el sub�ndice est� fuera de los l�mites, lanza una excepci�n
            throw new IndexOutOfBoundsException("Los sub�ndices de la lista deben estar en el rango: [0," + count + ") Entre");
        }
        // atravesar desde el primer nodo
        Node node = this.first;
        for (int i = 0; i < index; i++) {
            // Ir al nodo correspondiente al sub�ndice
            node = node.next;
        }
        // Devuelve el nodo atravesado
        return node;
    }

    /**
           * Eliminar un nodo
     *
           * @param node El nodo que se eliminar�
     */
    private void removeNode(Node node) {
        if (count == 1) {
            // Si solo hay un nodo en esta lista vinculada
            // Luego borra la lista vinculada
            this.first = null;
            this.last = null;
            // N�mero de nodos -1
            count--;
            return;
        }
        if (node == this.first) {
            // Si necesita eliminar el primer nodo
            // Modifica el siguiente nodo del nodo al primero
            this.first = node.next;
            // Establecer el nodo anterior del siguiente nodo de nodo en nulo
            node.next.previous = null;
        } else if (node == this.last) {
            // Si necesita eliminar el �ltimo nodo
            // Modifica el �ltimo nodo del nodo al �ltimo
            this.last = node.previous;
            // Establecer el siguiente nodo del nodo anterior del nodo en nulo
            node.previous.next = null;
        } else {
            // elimina el nodo en el medio
            // Apunta el nodo anterior del siguiente nodo del nodo al nodo anterior del nodo
            node.next.previous = node.previous;
            // Apunte el siguiente nodo del nodo anterior del nodo al siguiente nodo del nodo
            node.previous.next = node.next;
        }
        // Eliminar todos los puntos del nodo
        node.previous = null;
        node.next = null;
        // N�mero de elementos -1
        count--;
    }

    /**
           * Agregar un nodo despu�s de la lista vinculada
     *
           * @param element el valor del elemento del nuevo nodo
     */
    public void add(T element) {
        // crear una instancia de un objeto Node
        Node node = new Node(element);
        if (count == 0) {
            // Si no hay nodos en la lista vinculada
            // El nuevo elemento es el primero
            this.first = node;
        } else {
            // Si hay otros nodos en la lista vinculada
            // luego agregar al �ltimo elemento a su vez
            this.last.next = node;
            node.previous = this.last;
        }
        this.last = node;
        // N�mero de elementos +1
        count++;
    }

    /**
           * Agregar nodos seg�n sub�ndice
     *
           * @param index Necesita agregar el sub�ndice del nodo
           * @param element el valor del nuevo nodo
     */
    public void add(int index, T element) {
        // crear una instancia de un nuevo nodo
        Node newNode = new Node(element);
        if (index == 0) {
            // agrega el primer nodo
            // Apunta a newNode junto al primer nodo original
            newNode.next = this.first;
            // Apunta el anterior del original primero a newNode
            this.first.previous = newNode;
            // Modifica el primer nodo a newNode
            this.first = newNode;
        } else if (index == count) {
            // agrega el �ltimo nodo
            // Apunta el siguiente del �ltimo original a newNode
            this.last.next = newNode;
            // Se�ala el nuevo nodo anterior al �ltimo original
            newNode.previous = this.last;
            // Modifica el �ltimo nodo a newNode
            this.last = newNode;
        } else {
            // Verifique el sub�ndice y obtenga el nodo correspondiente al sub�ndice
            Node node = getNode(index);
            // Modificaci�n del nodo intermedio
            // El nodo anterior del nuevo nodo es el nodo anterior del nodo sub�ndice original
            newNode.previous = node.previous;
            // El siguiente nodo del nuevo nodo es el sub�ndice original.
            newNode.next = node;
            // Modificar el siguiente nodo del nodo anterior del nodo original como el nuevo nodo
            node.previous.next = newNode;
            // Modifica el nodo anterior del nodo original como un nuevo nodo
            node.previous = newNode;
        }
        // N�mero de elementos +1
        count++;
    }

    /**
           * Eliminar nodos seg�n sub�ndice
     *
           * @param index Necesita eliminar el sub�ndice del nodo
           * @return valor eliminado correctamente
     */
    public T remove(int index) {
        // Verifica el sub�ndice y obt�n el nodo
        Node node = getNode(index);
        // Eliminar nodo
        removeNode(node);
        // Devuelve el valor del nodo eliminado
        return node.element;
    }

    /**
           * Modificar el elemento especificado en la lista vinculada como el nuevo elemento
     *
           * @param index El sub�ndice que debe modificarse
           * @param elemento elemento modificado
           * @return el elemento antiguo antes de la modificaci�n
     */
    public T set(int index, T element) {
        // Verifica el sub�ndice y obt�n el nodo correspondiente del sub�ndice
        Node node = getNode(index);
        T oldElement = node.element;
        // Modificar el valor del elemento del nodo
        node.element = element;
        // Devuelve el elemento antiguo antes de la modificaci�n
        return oldElement;
    }

    /**
           * Obtener el elemento del sub�ndice especificado en la lista vinculada
     *
           * @param index El sub�ndice que se debe obtener
           * @return devuelve el elemento especificado
     */
    public T get(int index) {
        // Verifica el sub�ndice y obt�n el nodo correspondiente del sub�ndice
        Node node = getNode(index);
        // Obtiene el valor del elemento correspondiente al sub�ndice
        return node.element;
    }

    /**
           * Consultar el �ndice de la primera aparici�n de un elemento en la lista vinculada
     *
           * @param element El elemento que se va a consultar
           * @return la primera aparici�n del sub�ndice
     */
    public int indexOf(T element) {
        // Obtiene el primer nodo de la lista vinculada
        Node node = this.first;
        // Recorre los nodos de la lista enlazada y compara elementos
        for (int i = 0; i < size(); i++) {
            if (!element.equals(node.element)) {
            } else {
                // Devuelve la primera aparici�n del sub�ndice
                return i;
            }
            node = node.next;
        }
        // devuelve -1 si no se encuentra
        return -1;
    }

    /**
           * Determinar si el elemento especificado est� contenido en la lista vinculada
     *
           * @param element El elemento a juzgar
           * @return resultado del juicio
     */
    public boolean contains(T element) {
        return indexOf(element) != -1;
    }


    /**
           * Eliminar el elemento especificado en la lista vinculada
     *
           * @param element El elemento a eliminar
     * @return se elimin� correctamente
     */
    public boolean remove(T element) {
        // Obtiene el primer nodo de la lista vinculada
        Node node = this.first;
        // Registra el n�mero de elementos eliminados
        int removeCnt = 0;
        // Recorre los nodos de la lista enlazada y compara elementos
        for (int i = 0; i < size(); i++) {
            if (element.equals(node.element)) {
                // Elimina los elementos que cumplen los requisitos
                removeNode(node);
                // contador +1
                removeCnt++;
            }
            node = node.next;
        }
        return removeCnt != 0;
    }

    // Si solo elimina la primera aparici�n
    /*
    public boolean remove(T element) {
        int index = indexOf(element);
        if (index == -1) {
            return false;
        }
        remove(index);
        return true;
    }
    */

    /**
           * Borrar todos los datos en la lista vinculada
     */
    public void clear() {
        this.first = null;
        this.last = null;
        count = 0;
    }


    @Override
    public String toString() {
        // crear una instancia de un objeto StringBuilder
        if (count == 0) {
            // Si la lista vinculada est� vac�a, regrese directamente []
            return "[]";
        }
        StringBuilder sb = new StringBuilder("[ ");
        // comienza a hacer un bucle desde el primer nodo
        Node node = this.first;
        for (int i = 0; i < size(); i++) {
            // Adjuntar a StringBuilder
            sb.append(node.element).append(" , ");
            node = node.next;
        }
        sb.replace(sb.length() - 3, sb.length(), " ]");
        return sb.toString();
    }
}