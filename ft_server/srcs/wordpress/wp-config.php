<?php
/**
 * Основные параметры WordPress.
 *
 * Скрипт для создания wp-config.php использует этот файл в процессе
 * установки. Необязательно использовать веб-интерфейс, можно
 * скопировать файл в "wp-config.php" и заполнить значения вручную.
 *
 * Этот файл содержит следующие параметры:
 *
 * * Настройки MySQL
 * * Секретные ключи
 * * Префикс таблиц базы данных
 * * ABSPATH
 *
 * @link https://ru.wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Параметры MySQL: Эту информацию можно получить у вашего хостинг-провайдера ** //
/** Имя базы данных для WordPress */
define( 'DB_NAME', 'wordpress' );

/** Имя пользователя MySQL */
define( 'DB_USER', 'root' );

/** Пароль к базе данных MySQL */
define( 'DB_PASSWORD', '' );

/** Имя сервера MySQL */
define( 'DB_HOST', 'localhost' );

/** Кодировка базы данных для создания таблиц. */
define( 'DB_CHARSET', 'utf8mb4' );

/** Схема сопоставления. Не меняйте, если не уверены. */
define( 'DB_COLLATE', '' );

/**#@+
 * Уникальные ключи и соли для аутентификации.
 *
 * Смените значение каждой константы на уникальную фразу.
 * Можно сгенерировать их с помощью {@link https://api.wordpress.org/secret-key/1.1/salt/ сервиса ключей на WordPress.org}
 * Можно изменить их, чтобы сделать существующие файлы cookies недействительными. Пользователям потребуется авторизоваться снова.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         ':]]]9.S{3+-by~#8ZMlN<~As0Q^.U,/?H~d>Qdfo,ClP.n%5u:|nt6HfiD20Ux16' );
define( 'SECURE_AUTH_KEY',  'Zr/1,wvPE}XMhB]5czEDi@Yq$[Z?p$mQQ-`IDJ1)|I>%mvgUs(!H7?|]|MUGVYQx' );
define( 'LOGGED_IN_KEY',    'a95:_Q s n1{_2Xji;W>C~*R$$*ND<XZb~YxPo9T*@v!!$zUhRzk0q[aI+<!qBn=' );
define( 'NONCE_KEY',        '6.I__Rixoc2]9c7=y4tp+Lwobn%1J{G;L]b=#z&HTF`g||mi9*~%UP(~7m6]GJlD' );
define( 'AUTH_SALT',        ';^CY5) D-0DwNd}=oFqj_(,pR]H a1/aaBnH4Y*@}q3JV&:/Jw~swj_7x8xmz[Sf' );
define( 'SECURE_AUTH_SALT', 'F2]I/V%#*aN`d&5Ae}rp>/BtMXGxYkD#;pTCwvqhIal{m9jf+J$aGv@i2ln]<G2N' );
define( 'LOGGED_IN_SALT',   '@ ysUC9jc o+yxz42Ihd$}A@KAx,9JgPA?{y(Wd-uo5iQ5Ae=^r=M)%YuEV8Szz/' );
define( 'NONCE_SALT',       'wjOL~)0y~?UGJ!foh<O?z(0pVRR1v@z=LJFtzd;cAWG0[%xqIW]}xji-cW}~#%Ck' );

/**#@-*/

/**
 * Префикс таблиц в базе данных WordPress.
 *
 * Можно установить несколько сайтов в одну базу данных, если использовать
 * разные префиксы. Пожалуйста, указывайте только цифры, буквы и знак подчеркивания.
 */
$table_prefix = 'wp_';

/**
 * Для разработчиков: Режим отладки WordPress.
 *
 * Измените это значение на true, чтобы включить отображение уведомлений при разработке.
 * Разработчикам плагинов и тем настоятельно рекомендуется использовать WP_DEBUG
 * в своём рабочем окружении.
 *
 * Информацию о других отладочных константах можно найти в документации.
 *
 * @link https://ru.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Это всё, дальше не редактируем. Успехов! */

/** Абсолютный путь к директории WordPress. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Инициализирует переменные WordPress и подключает файлы. */
require_once ABSPATH . 'wp-settings.php';

